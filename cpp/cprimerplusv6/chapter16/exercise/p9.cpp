/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p9.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::list;
    using std::vector;
    
    cout << "Enter the size of vector and list: ";
    int container_size;
    cin >> container_size;

    // 第一步
    srand(time(0));
    vector<int> vi0(container_size);
    for (int i = 0; i < container_size; i++) {
        vi0[i] = random();
    }

    // 第二步
    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());

    // 第三步
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t t_vector_sort = clock();

    li.sort();
    clock_t t_list_sort = clock();

    // 第四步
    copy(vi0.begin(), vi0.end(), li.begin());
    clock_t new_start = clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    clock_t t_copy_sort = clock();

    // 统计并输出时间
    cout << "vector sort cost time: ";
    cout << (double)(t_vector_sort - start) / CLOCKS_PER_SEC << endl;
    cout << "list sort cost time: ";
    cout << (double)(t_list_sort - t_vector_sort) / CLOCKS_PER_SEC << endl;
    cout << "copy sort cost time: ";
    cout << (double)(t_copy_sort - new_start) / CLOCKS_PER_SEC << endl;

    return 0;
}