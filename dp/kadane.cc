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

/*

Kadane's Algorithm is an algorithm that can find the maximum sum subarray
given an array of numbers in O(n) time and O(1) space. Its implementation is a
very simple example of dynamic programming, and the efficiency of the algorithm
allows it to be a powerful tool in some DP algorithms. If you haven't already
solved Maximum Subarray, take a quick look at the problem before continuing with
this article - Kadane's Algorithm specifically solves this problem.

Kadane's Algorithm involves iterating through the array using an integer variable
`current`, and at each index `i`, determines if elements before index `i` are
"worth" keeping, or if they should be "discarded". The algorithm is only useful
when the array can contain negative numbers. If `current` becomes negative,
it is reset, and we start considering a new subarray starting at the current index.

Pseudocode for the algorithm is below:

// Given an input array of numbers "nums",
1. best = negative infinity
2. current = 0
3. for num in nums:
    3.1. current = Max(current + num, num)
    3.2. best = Max(best, current)

4. return best
*/