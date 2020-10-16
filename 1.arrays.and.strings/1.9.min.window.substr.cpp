/**
 * @file 1.9.min.window.substr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

class Solution {
 public:
  // 1 collect required freqency of characters
  // Expand the window until all characters are inside window
  // Shrink until one required character is missing and update best
  string minWindow(string t, string p) {
    pair<int, int> best = {0, 0};
    int n = t.size(), m = p.size(), f[128];

    memset(f, 0, sizeof f);

    for (auto c : p) ++f[c - 'A'];

    // left, right, characters present in [l,r]
    for (int l = 0, r = 0, k = 0; r < n; ++r) {
      if (--f[t[r] - 'A'] >= 0) ++k;
      while (k == m) {
        // update best and shrink
        if (!best.ss || r - l + 1 < best.ss) best = {l, r - l + 1};
        if (++f[t[l++] - 'A'] > 0) --k;
      }
    }

    return t.substr(best.ff, best.ss);
  }
};