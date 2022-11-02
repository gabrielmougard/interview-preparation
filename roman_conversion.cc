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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        struct romandata_t { unsigned int value; char const* numeral; };
        const struct romandata_t romandata[] =
        {
            {1000, "M"}, {900, "CM"},
            {500, "D"}, {400, "CD"},
            {100, "C"}, { 90, "XC"},
            { 50, "L"}, { 40, "XL"},
            { 10, "X"}, { 9, "IX"},
            { 5, "V"}, { 4, "IV"},
            { 1, "I"},
            { 0, NULL} // end marker
        };

        string result;
        for (const romandata_t* current = romandata; current->value > 0; ++current) {
            while (num >= current->value)
            {
                result += current->numeral;
                num -= current->value;
            }
        }
        return result;
    }
};