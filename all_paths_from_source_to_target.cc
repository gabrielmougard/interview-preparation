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

// https://leetcode.com/explore/learn/card/graph/619/depth-first-search-in-graph/3849/

#include<bits/stdc++.h>

using namespace std;

// time complexity : O((2^N) * N)
// space complexity : O(N)

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // create graph
        unordered_map<int, list<int>> graphModified;
        for (size_t i = 0; i < n; i++) {
            for (const auto &e : graph[i]) {
                graphModified[i].push_back(e);
            }
        }
        
        vector<vector<int>> paths;
        
        function<void(int, vector<int>)> dfs;
        dfs = [&](int curVertex, vector<int> curPath) {
            if (curVertex == n-1) {
                // append path and return
                paths.push_back(curPath);
                return;
            }
            
            for (const auto &neighbor : graphModified[curVertex]) {
                auto newCurPath = curPath;
                newCurPath.push_back(neighbor);
                dfs(neighbor, newCurPath);
            }   
        };
        
        dfs(0, {0});
        return paths;
    }
};

