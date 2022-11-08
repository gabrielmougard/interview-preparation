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

// https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4046/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if (n==0) return 0;
        int m=matrix[0].size();
        if (m==0) return 0;
        vector<vector<int>> psum (n+1, vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int cur=matrix[i-1][j-1]-'0';
                psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+cur;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int k=0;
                for(k=1;k<=i && k<=j;k++){
                    if (psum[i][j]-psum[i][j-k]-psum[i-k][j]+psum[i-k][j-k]!=k*k) break;
                }
                ans=max(ans, k-1);
            }
        }
        return ans*ans;
    }
};