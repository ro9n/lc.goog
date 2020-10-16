/**
 * @file 1.1.longest.substr.without.repeat
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday October 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size(), best = 0;
    vector<int> indices(128 - 32, -1);

    for (int l = 0, r = 0; r < n; ++r) {
      int x = s[r] - 32;  // space
      if (~indices[x]) l = max(l, indices[x] + 1);
      indices[x] = r;
      best = max(best, r - l + 1);
    }

    return best;
  }
};
