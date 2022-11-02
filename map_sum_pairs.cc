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

// https://leetcode.com/explore/learn/card/trie/148/practical-application-i/1058/

#include<bits/stdc++.h>

using namespace std;

struct MapNode {
    unordered_map<char, MapNode*> children;
    int score;
    
    MapNode() {
        score = 0;
    }
};

class MapSum {
public:
    unordered_map<string, int> m;
    MapNode* root;
    
    MapSum() {
        root = new MapNode();    
    }
    
    void insert(string key, int val) {
        int delta;
        if (m.find(key) != m.end()) {
            delta = val - m[key];
        } else {
            delta = val;
        }
        m[key] = val;
        MapNode* cur = root;
        cur->score += delta;
        for (const auto &c : key) {
            if (cur->children[c] == nullptr) {
                cur->children[c] = new MapNode();
            }
            cur = cur->children[c];
            cur->score += delta;
        }
    }
    
    int sum(string prefix) {
        MapNode* cur = root;
        for (const auto &c : prefix) {
            cur = cur->children[c];
            if (cur == nullptr)
                return 0;
        }
        return cur->score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */