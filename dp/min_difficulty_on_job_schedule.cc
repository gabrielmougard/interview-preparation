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

// https://leetcode.com/explore/featured/card/dynamic-programming/632/common-patterns-in-dp-problems/4110/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        // If we cannot schedule at least one job per day, 
        // it is impossible to create a schedule
        if (n < d) return -1;

        int hardestJobRemaining[n];
        memset(hardestJobRemaining, -1, n);

        int hardestJob = 0;
        for (int i = n-1; i >= 0; i--) {
            hardestJob = max(hardestJob, jobDifficulty[i]);
            hardestJobRemaining[i] = hardestJob;
        }

        // initialize memo array with value of -1
        int memo[n][d+1];
        memset(memo, -1, sizeof(memo));

        // declare our recursion
        function<int(int, int)> dp;
        dp = [&](int i, int day) -> int {
            // base cases
            if (day == d) return hardestJobRemaining[i];

            if (memo[i][day] == -1) {
                int best = INT_MAX;
                int hardest = 0;

                // iterate through the options and choose the best
                for (int j = i; j < n-(d-day); j++) {
                    hardest = max(hardest, jobDifficulty[j]);
                    // recurrence relation
                    best = min(best, hardest + dp(j+1, day+1));
                }
                memo[i][day] = best;
            }
            return memo[i][day];
        };

        return dp(0, 1);
    }
};