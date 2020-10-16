/**
 * @file 1.2.container.with.most.water
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
  int maxArea(vector<int>& h) {
    int best = 0;
    for (int n = h.size(), l = 0, r = n - 1; l < r;) {
      best = max(best, (r - l) * min(h[l], h[r]));
      if (h[l] < h[r]) ++l;
      else
        --r;
    }

    return best;
  }
};
