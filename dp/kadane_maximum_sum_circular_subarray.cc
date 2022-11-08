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

// https://leetcode.com/explore/featured/card/dynamic-programming/633/common-patterns-continued/4142/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> A) {
        int S = 0;  // S = sum(A)
        for (int x : A) {
            S += x;
        }
        
        if (A.size() == 1) {
            return S;
        }

        int ans1 = kadane(A, 0, A.size() - 1, 1);
        int ans2 = S + kadane(A, 1, A.size() - 1, -1);
        int ans3 = S + kadane(A, 0, A.size() - 2, -1);
        return max(ans1, max(ans2, ans3));
    }

    int kadane(vector<int> A, int i, int j, int sign) {
        // The maximum non-empty subarray for array
        // [sign * A[i], sign * A[i+1], ..., sign * A[j]]
        int ans = INT_MIN;
        int cur = INT_MIN;
        for (int k = i; k <= j; ++k) {
            cur = sign * A[k] + max(cur, 0);
            ans = max(ans, cur);
        }
        return ans;
    }
};