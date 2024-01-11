/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC226.cpp
*   Author：leekaihua
*   Date：2023年12月05日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 探查包含O的区域，是否被包围。
    // 方法是，广度优先遍历，O组成的区域不会达到边界
    void BFS(vector<vector<char>>& board, int i, int j, bool& is_surrounded) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        if (board[i][j] != 'O') {
            return;
        }
        if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) {
            is_surrounded = false;
        }
        board[i][j] = '1';
        BFS(board, i - 1, j, is_surrounded);
        BFS(board, i + 1, j, is_surrounded);
        BFS(board, i, j - 1, is_surrounded);    
        BFS(board, i, j + 1, is_surrounded);    
    }

    // 如果O组成的区域是一个被包含的区域，那么将区域内的字符变成X
    void BFS_change_status(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != '1') {
            return;
        }
        board[i][j] = 'X';
        BFS_change_status(board, i - 1, j);
        BFS_change_status(board, i + 1, j);
        BFS_change_status(board, i, j - 1);
        BFS_change_status(board, i, j + 1);
    }

    // 遍历，如果遇到O，那么探查其所在的区域是否是被包含的，并将区域标注为1。表示探查过了。
    // 将确定是被包围的区域的字符标记为X。
    // 将不是被包围，但是标记为1的预期的字符还原为O。
    vector<vector<char> > surroundedArea(vector<vector<char> >& board) {
        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'X' || board[i][j] == '1') {
                    continue;
                }
                bool is_surrounded = true;
                BFS(board, i, j, is_surrounded);
                if (is_surrounded) {
                    BFS_change_status(board, i, j);
                }
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
        print_mat(board);
        return board;
    }

    void print_mat(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    // vector<vector<char>> board = {
    //         {'X','X','X','X'},
    //         {'X','O','O','X'},
    //         {'X','O','X','X'},
    //         {'X','X','O','X'}
    // };
    vector<vector<char>> board = {
        {'X','O','O','X','X','X','O','X','O','O'},
        {'X','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','O','X','X','X','X','X'},
        {'X','O','X','X','X','O','X','X','X','O'},
        {'O','X','X','X','O','X','O','X','O','X'},
        {'X','X','O','X','X','O','O','X','X','X'},
        {'O','X','X','O','O','X','O','X','X','O'},
        {'O','X','X','X','X','X','O','X','X','X'},
        {'X','O','O','X','X','O','X','X','O','O'},
        {'X','X','X','O','O','X','O','X','X','O'}
    };
    Solution instance;
    vector<vector<char>> result = instance.surroundedArea(board);

    return 0;
}