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

// https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4040/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return 0; // you start at index 0 and jump the whole array, no cost.
        if (n == 2) return min(cost[0], cost[1]); // start from the minimum and then jump from one or two to go out
        
        int dp[n+1];
        for (int i = 0; i < n; i++) dp[i] = 0;
        
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = min(cost[0], cost[1]);
        
        for (int i = 3; i <= n; i++) {
            dp[i] = min(cost[i-2]+dp[i-2], cost[i-1]+dp[i-1]);
        }
        
        return dp[n];
    }
};