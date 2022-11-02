// Copyright 2022 gab
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        if (x == -2147483648) {
            return 0;
        }
        int l = log10(abs(x));
        string res;
        string sign;
        if (x < 0) {
            sign = "-";
        }
        auto pos_x = abs(x);
        if (l < 1) { // 1 <= abs(x) <= 9 
            res += to_string(pos_x);
            auto signedRes = sign + res;
            return stoi(signedRes);    
        }
        if (l < 2) { // 10 <= abs(x) <= 99
            if (pos_x % 10 == 0) {
                res += to_string(pos_x/10);
                auto signedRes = sign + res;
                return stoi(signedRes);
            } 
            res += to_string(pos_x % 10);
            res += to_string(pos_x/10);
            auto signedRes = sign + res;
            return stoi(signedRes);    
        }
        bool ignore_zeroes = true;
        for (int i = 0; i <= l;i++) {
            int num = 0;
            if (i != l) {
                num = (pos_x / static_cast<int>(pow(10, i))) % 10;
            } else {
                num = pos_x / static_cast<int>(pow(10, i));
            }
            cout << num << " ";
            if (num != 0) {
                res += to_string(num);
                if (ignore_zeroes) {
                    ignore_zeroes = false;
                }
            } else {
                if (!ignore_zeroes) {
                    res += to_string(num);
                }
            }
        }

        // reversed number (still a string) limit
        string limit = "2147483647";
        if (res > limit && limit.size() == res.size()) {
            return 0;
        }

        auto signedRes = sign + res;
        return stoi(signedRes);
    }
};