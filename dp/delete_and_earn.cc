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

// https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4147/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        // base cases
        if (n == 1) return nums[0];
        if (n == 2) {
            if (abs(nums[0] - nums[1]) == 1) {
                return max(nums[0], nums[1]);
            }
            return nums[0] + nums[1];
        }
        
        // first, generate the points map : map elements to the number of points that
        // we can gain from taking each element.
        map<int, int> points;
        int largest = 0;
        for (int i = 0; i < n; i++) {
            if (points.find(nums[i]) == points.end()) points[nums[i]] = nums[i];
            else points[nums[i]] += nums[i];
        
            if (nums[i] > largest) largest = nums[i];
        }
        
        // second, define DP cache
        map<int, int> cache;
        
        function<int(int)> maxPoints;
        maxPoints = [&](int x)->int {
            // base recurrence cases
            if (x == 0) return 0;
            if (x == 1) return points[1];
            
            // if cache has been hit, return value
            if (cache.find(x) != cache.end()) {
                return cache[x];
            }
            
            auto m = max(points[x] + maxPoints(x-2), maxPoints(x-1));
            cache[x] = m;
            return m;
        };
        
        return maxPoints(largest);
    }
};