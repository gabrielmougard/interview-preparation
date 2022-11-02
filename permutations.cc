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

// https://leetcode.com/problems/permutations/submissions/818770913/

#include <bits/stdc++.h>

using namespace std;

class Solution {
     vector<vector<int>>ans;
public:
    vector<vector<int>> permute(vector<int>& A) {
        int n = A.size();
        solve(A,n);
        return ans;
        
    }
    void solve(vector<int>& a, int size)
    {
        if (size == 1) {
            ans.push_back(a);
            return;
        }

        for (int i = 0; i < size; i++) {
            solve(a, size - 1);
            if (size % 2 == 1)
                swap(a[0], a[size - 1]);
            else
                swap(a[i], a[size - 1]);
        }
    }

   
};