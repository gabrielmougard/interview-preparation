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

// https://leetcode.com/explore/learn/card/graph/619/depth-first-search-in-graph/3900/

#include<bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution{
public:
    unordered_map<Node*, Node*> mpp;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        if(mpp.find(node)!=mpp.end()){
            return mpp[node];
        }
        Node* t= new Node(node->val);
        mpp[node]=t;
        for(auto i: node->neighbors){
            t->neighbors.push_back(cloneGraph(i)); 
            
        }
        return t;
        
    }
};