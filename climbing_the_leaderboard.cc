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

// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

// complexity : O(m.log(n)) ==> case 6,7,8,9 still failing

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> result;
    
    // first, compute other player ranks
    vector<int> ranks = {1};
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] < ranked[i-1]) {
            ranks.push_back(ranks[i-1]+1);
        } else {
            ranks.push_back(ranks[i-1]);
        }
    }
    
    // second, define a custom binary search operation over the ranked dataset
    function<int(vector<int>,int,int)> binary_search;
    binary_search = [&ranks, &binary_search](vector<int> ranked, int offset, int score)->int{
        // first base case, array is only size 1
        if (ranked.size() == 1) {
            if (ranked[0] <= score) {
                return ranks[offset];
            } else if (ranked[0] > score) {
                return ranks[offset] + 1;
            }
        }
        
        auto mid = ranked.size() / 2;
        // second base case, we find the score
        if (ranked[mid] == score) {
            return ranks[offset+mid];
        }
        
        vector<int>::const_iterator first, last;
        
        if (ranked[mid] < score) {
            first = ranked.cbegin();
            last = ranked.cbegin() + mid;
            vector<int> sub_ranked(first, last);
            return binary_search(sub_ranked, offset, score);
        } else {
            first = ranked.cbegin() + mid;
            last = ranked.cbegin() + ranked.size();
            vector<int> sub_ranked(first, last);
            return binary_search(sub_ranked, offset + mid, score);
        }
    };
    
    // last, compute rank of the actual player for all the games
    for (const int &player_score : player) {
        result.push_back(binary_search(ranked, 0, player_score));
    }  
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
