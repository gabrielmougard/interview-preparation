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

// https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4146/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        int cache[m+1][m+1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                cache[i][j] = 0;
            }
        }

        for (int i = m-1; i >= 0; i--) { // iterate over multipliers
            for (int left = i; left >= 0; left--) { // iterate over nums
                int mult = multipliers[i];
                int right = n-1-(i - left);
                cache[i][left] = max(
                    mult*nums[left] + cache[i+1][left+1], // we choose the left 
                    mult*nums[right] + cache[i+1][left] // we choose right
                );
            }
        }

        return cache[0][0];
    }
};