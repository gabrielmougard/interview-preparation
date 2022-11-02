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

// https://www.hackerrank.com/challenges/absolute-permutation/problem?isFullScreen=true

// complexity : O(n), space : O(n)

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

vector<int> absolutePermutation(int n, int k) {

/*   __________________________________________
    | | i-k |  ...  | i |  ...  | i+k |        |
    |_|_____|_______|__ |_______|_____|________|

    If n is not divisible by 2k, then there is no solution
    because there will be remaining blocs with no absolute
    difference of k. If the condition is fulfilled, then all
    the i - k goes first because they are smaller and if they are
    already placed, we push the i + k (if they don't exceed n)   

*/

    unordered_map<int, bool> m;
    for(int i = 1; i <= n; i++) {
        m[i] = true;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(m[i - k] == true) {
            ans.push_back(i - k);
            m[i - k] = false;
        } else {
            if(i + k > n) return {-1};
            ans.push_back(i + k);
            m[i + k] = false;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(m[i] == true) return {-1};
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
