/**
 * @file 1.11.longest.substr.with.at.most.two.distinct.char
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
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size(), c1 = -1, c2 = -1, best = 0;

    for (int l = 0, r = 0; r < n; ++r) {
      if (c1 == -1) c1 = r;
      else if (s[r] != s[c1] && c2 == -1)
        c2 = r;
      else if (s[r] != s[c1] && s[r] != s[c2])
        l = min(c1, c2) + 1, c1 = max(c1, c2), c2 = r;
      else if (s[r] == s[c1])
        c1 = r;
      else if (s[r] == s[c2])
        c2 = r;

      best = max(best, r - l + 1);
    }

    return best;
  }
};