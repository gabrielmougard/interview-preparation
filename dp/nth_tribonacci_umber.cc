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

// https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4041/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;
        
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];  
        }
        return dp[n];
    }
};