/**
 * @file 1.16.maximize.distance.to.closest.person
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;

class Solution {
 public:
  int maxDistToClosest(vector<int>& s) {
    int n = s.size(), l[n], r[n];
    l[0] = s[0] ? 0 : -INF, r[n - 1] = s[n - 1] ? n - 1 : INF;

    for (int i = 0; i < n; ++i) {
      if (i > 0) l[i] = s[i] ? i : l[i - 1];
      if (i < n - 1) r[n - 2 - i] = s[n - 2 - i] ? n - 2 - i : r[n - 1 - i];
    }

    int best = 0;
    for(int i = 0; i < n; ++i) {
      if (!s[i]) {
        best = max(best, min(i - l[i], r[i] - i));
      }
    }

    return best;
  }
};