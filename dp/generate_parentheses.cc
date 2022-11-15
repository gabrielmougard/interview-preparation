// https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        function<void(vector<string>&, string&, int, int, int)> backtrack;
        backtrack = [&](vector<string> &ans, string &cur, int open, int close, int max) -> void{
            if (cur.length() == max * 2) {
                ans.push_back(cur);
                return;
            }

            if (open < max) {
                cur += "(";
                backtrack(ans, cur, open+1, close, max);
                cur.erase(cur.begin() + cur.length() - 1, cur.begin() + cur.length());
            }
            if (close < open) {
                cur += ")";
                backtrack(ans, cur, open, close+1, max);
                cur.erase(cur.begin() + cur.length() - 1, cur.begin() + cur.length());
            }
        };

        vector<string> ans = {};
        string builder;
        backtrack(ans, builder, 0, 0, n);
        return ans;
    }
};