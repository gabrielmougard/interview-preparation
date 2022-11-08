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

// https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4045/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        // base case, if both strings are of length 1
        if (n1 == 1 && n2 == 1) return (text1[0] == text2[0]) ? 1 : 0;
        
        // dynamic programming
        int cache[n1+1][n2+1];
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) {
                    cache[i][j] = 0;
                }
                else if (text1[i-1] == text2[j-1]) {
                    cache[i][j] = 1 + cache[i-1][j-1];
                } else {
                    cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
                }
            }   
        }
        return cache[n1][n2];
        
        
    }
};