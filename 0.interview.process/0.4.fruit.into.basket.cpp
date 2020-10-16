/**
 * @file 0.4.fruit.into.basket
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday October 13 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& s) {
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

/*
class Solution {
 public:
  int totalFruit(vector<int>& f) {
    int c1 = -1, c2 = -1;
    int n = f.size(), best = 1;
    vector<int> m(n, -1);

    for (int l = 0, r = 0; r < n; ++r) {
      if (m[f[r]] == -1) {
        if (~c1 && ~c2 && m[c2] < m[c1]) swap(c1, c2);
        if (~c1) l = m[c1] + 1, m[c1] = -1;
        if (~c2) c1 = c2;
        c2 = f[r];
      }
      m[f[r]] = r;
      best = max(best, r - l + 1);
    }

    return best;
  }
};
*/