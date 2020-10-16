/**
 * @file 1.12.missing.ranges
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ranges;

    auto add_range = [&ranges](int i, int j) {
      if (j < i) return;
      else if (i == j)
        ranges.push_back(to_string(i));
      else
        ranges.push_back(to_string(i) + "->" + to_string(j));
    };

    for (int n = nums.size(), l, r, i = 0; i <= n; ++i) {
      // choose a valid l, r that is missing
      l = i > 0 ? nums[i - 1] + 1 : lower, r = i < n ? nums[i] - 1 : upper;
      add_range(l, r);
    }

    return ranges;
  }
};