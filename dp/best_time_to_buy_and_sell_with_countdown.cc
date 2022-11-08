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

// https://leetcode.com/explore/featured/card/dynamic-programming/632/common-patterns-in-dp-problems/4118/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> prices) {

    int sold = INT_MIN, held = INT_MIN, reset = 0;

    for (int price : prices) {
      int preSold = sold;

      sold = held + price;
      held = max(held, reset - price);
      reset = max(reset, preSold);
    }

    return max(sold, reset);
  }
};