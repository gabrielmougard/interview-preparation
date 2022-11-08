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

// https://leetcode.com/explore/featured/card/dynamic-programming/632/common-patterns-in-dp-problems/4111/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // base case where amount == 0
        if (amount < 1) return 0;
        
        int memo[amount];
        memset(memo, 0, sizeof(memo));
        
        // recurrence relation
        function<int(int)> dp;
        dp = [&](int curr_amount)->int {
            // base cases
            if (curr_amount < 0) return -1;
            if (curr_amount == 0) return 0;
            if (memo[curr_amount - 1] != 0) return memo[curr_amount - 1];
            
            int minimum = INT_MAX;
            for (const auto &c : coins) {
                int res  = dp(curr_amount - c);
                if (res >= 0 && res < minimum) minimum = 1 + res;
            }
            if (minimum == INT_MAX)
                memo[curr_amount-1] = -1;
            else
                memo[curr_amount-1] = minimum;
            
            return memo[curr_amount-1];
        };
        return dp(amount);
    }
};