/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM85.cpp
*   Author：leekaihua
*   Date：2023年04月24日
*   Brife：
*



*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    private:
        bool is_ipv4(string& ip) {
            int num = 0;
            int length = ip.length();
            int i = 0;
            int count = 0;
            bool start_with_0 = false;
            while (i < length) {
                int j = 0;
                while (i + j < length && ip[i + j] != '.') {
                    if (j == 0 && ip[i + j] == '0') {
                        start_with_0 = true;
                    }
                    if (!isdigit(ip[i + j])) {
                        return false;
                    }
                    num = num * 10 + ip[i + j] - 48;
                    j++;
                }
                i = i + j + 1;
                if (start_with_0 && num != 0) {
                    return false;
                }
                if (num > 255) {
                    return false;
                }
                start_with_0 = false;
                num = 0;
                count++;
            }
            
            if (count == 4) {
                return true;
            }
            return false;
        }

        bool is_ipv6(string& ip) {
            int i = 0;
            int count = 0;
            string temp = "";
            if (ip.length() == 0) {
                return false;
            }
            if (!isalnum(ip[0]) || !isalnum(ip[ip.length() - 1])) {
                return false;
            }
            while (i < ip.length()) {
                int j = 0;
                while (i + j < ip.length() && ip[i + j] != ':') {
                    if (!isdigit(ip[i + j]) 
                            && !(isalpha(ip[i + j]) 
                            && (ip[i + j] > 64 && ip[i + j] < 71
                            || ip[i + j] > 96 && ip[i + j] < 103))) {
                        return false;
                    }
                    temp += ip[i + j];
                    j++;
                }
                i = i + j + 1;
                if (temp.length() > 4 || temp == "") {
                    return false;
                }
                if (temp.length() > 1 && temp[0] == '0' && temp[1] == '0') {
                    return false;
                }
                temp = "";
                count++;
            }
            if (count != 8) {
                return false;
            }
            return true;
        }

    public:
        string solve(string IP) {
            if (is_ipv4(IP)) {
                return "IPv4";
            } else if (is_ipv6(IP)) {
                return "IPv6";
            } else {
                return "Neither";
            }
        }

};

int main() {
    Solution instance;
    string result = "";
    // string ip1 = "172.16.254.1";
    // result = instance.solve(ip1);
    // cout << ip1 << " " << result << endl;
    // string ip2 = "256.256.256.256";
    // result = instance.solve(ip2);
    // cout << ip2 << " " << result << endl;
    // string ip3 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    // result = instance.solve(ip3);
    // cout << ip3 << " " << result << endl;
    // string ip4 = "2001:db8:85a3:0:0:8A2E:0370:7334";
    // result = instance.solve(ip4);
    // cout << ip4 << " " << result << endl;
    // string ip5 = "2001:0db8:85a3::8A2E:0370:7334";
    // result = instance.solve(ip5);
    // cout << ip5 << " " << result << endl;
    // string ip6 = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
    // result = instance.solve(ip6);
    // cout << ip6 << " " << result << endl;
    // string ip7 = "20EE:FGb8:85a3:0:0:8A2E:0370:7334";
    // result = instance.solve(ip7);
    // cout << ip7 << " " << result << endl;
    string ip8 = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    result = instance.solve(ip8);
    cout << ip8 << " " << result << endl;

    return 0;
}