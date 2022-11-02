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

// https://leetcode.com/explore/learn/card/graph/619/depth-first-search-in-graph/3901/

#include<bits/stdc++.h>

using namespace std;

template<typename Cont, typename T>
void insert_sorted(Cont& container, const T& item) {
    const auto insert_pos = std::lower_bound(std::begin(container), std::end(container), item);
    container.insert(insert_pos, item);
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // MORE INTERESTING VERSION OF THE PROBLEM
        // WHERE WE NEED TO START WITH THE "HIGHEST OUTGOING NODE" (aka to find the longest itinerary)

        // 1) find source node & build graph: have highest ratio of outgoing edges
        int n = tickets.size(); // numEdges
        unordered_map<string, int> weights;
        unordered_map<string, vector<string>> graph;
        for (const auto &e : tickets) {
            auto src = e[0];
            auto dest = e[1];
            if (graph.find(src) != graph.end()) {
                insert_sorted(graph[src], dest); // maintain sorted order of adjacency list for later
            } else {
                graph[src] = {dest};
            }
            if (weights.find(src) != weights.end()) {
                weights[src] += 1;
            } else {
                weights[src] = 1;
            }
            if (weights.find(dest) != weights.end()) {
                weights[dest] -= 1;
            } else {
                weights[dest] = -1;
            }
        }
        
        string source;
        int outCount = -n;
        for (auto it = weights.begin(); it != weights.end(); it++) {
            auto c = it->second; 
            if (c > outCount) {
                source = it->first;
                outCount = c;
            }
        }
        
        // dfs from source
        vector<string> path;
        unordered_map<string, bool> visited;
        int edgeCount = 0;
        function<void(string)> dfs;
        dfs = [&](string curVertex){
            if (edgeCount == n+1) {
                return;
            }
            if (graph[curVertex].size() == 0) { // "leaf" vertex, just add to path
                path.push_back(curVertex);
            } else {
                if (edgeCount == n) {
                    path.push_back(curVertex);
                } else {
                    for (const auto &neighbor : graph[curVertex]) {
                        stringstream edgeName;
                        edgeName << curVertex << "->" << neighbor;
                        if (visited.find(edgeName.str()) == visited.end()) {
                            visited[edgeName.str()] = true;
                            path.push_back(curVertex);
                            edgeCount++;
                            dfs(neighbor);
                        }
                    }   
                }   
            }
        };
        
        dfs(source);
        return path;
    }
};

// ORIGINAL problem : always starting at "JFK"
class Solution2 {
public:
    vector<string> res;
    
    // adjacency list
    unordered_map<string, multiset<string>> mp;
    bool dfs(string u, int n) {
        // if we have traversed all the edges, then return 1
        if(res.size() == n + 1)
            return true;
        // if if there is no. adjacent of curr node, then return false
        if(mp[u].size() == 0)
            return false;
        multiset<string> s = mp[u];
        // check for all the adjacents of curr node
        for(auto v : s) {   
            // find the address of adjacent node  
            auto it = mp[u].find(v);  
            // erase the adjacent node 
            mp[u].erase(it); 
            // push the adjacent node into res 
            res.push_back(v);
            // if the curr path lead to result then return true
            if(dfs(v, n))
                return true;
            // else backtrack  
            else {
                res.pop_back();
                mp[u].insert(v);
            }
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        // make adjacency list
        for(int i = 0; i < tickets.size(); i++) {
            string u = tickets[i][0];
            string v = tickets[i][1];
            mp[u].insert(v);
        }
        
        // push the initial value
        res.push_back("JFK");
        dfs("JFK", n);
        return res;
    }
};