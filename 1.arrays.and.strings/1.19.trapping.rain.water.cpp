/**
 * @file 1.19.trapping.rain.water
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& h) {
    if (h.empty()) return 0;
    int n = h.size(), l[n], r[n];

    for (int i = 0; i < n; ++i) {
      l[i] = i > 0 ? max(l[i - 1], h[i]) : h[0];
      r[n - 1 - i] = n - 1 - i < n - 1 ? max(r[n - i], h[n - 1 - i]) : h[n - 1];
    }

    int q = 0; // quantity
    for(int i = 0; i < n; ++i) {
      q += min(l[i], r[i]) - h[i];
    }

    return q;
  }
};
