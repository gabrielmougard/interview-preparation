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

// https://leetcode.com/explore/learn/card/graph/619/depth-first-search-in-graph/3893/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, vector<bool>& seen, int currNode, int destination) {
        if (currNode == destination) {
            return true;
        }
        if (!seen[currNode]) {
            seen[currNode] = true;
            for (auto& nextNode : graph[currNode]) {
                if (dfs(graph, seen, nextNode, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> seen(n);
        return dfs(graph, seen, source, destination);
    }
};

class Solution2 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Store all edges according to nodes in 'graph'.
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // Start from source node, add it to stack.
        // NOTE: 'stack' conflicts with the type name std::stack, 
        // so we use 'dfsStack' instead.
        vector<bool> seen(n);
        stack<int> dfsStack({source});
        seen[source] = true;
        
        while (!dfsStack.empty()) {
            int currNode = dfsStack.top();
            dfsStack.pop();
            
            if (currNode == destination) {
                return true;
            }
            
            // Add all unvisited neighbors of the current node to 'dfsStack' 
            // and mark them as visited.
            for (auto nextNode : graph[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    dfsStack.push(nextNode);
                }
            }
        }
        
        return false;
    }
};

class UnionFind {
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }   
    void join(int x, int y) {
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > root[rootY]) {
                swap(rootX, rootY);
            }
            // Modify the root of the smaller group as the root of the
            // larger group, also increment the size of the larger group.
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
};

class Solution3 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);

        for (auto& edge : edges) {
            uf.join(edge[0], edge[1]);
        }
        
        return uf.find(source) == uf.find(destination);
    }
};