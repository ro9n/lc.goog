/**
 * @file 1.3.3sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday October 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& v) {
    if (v.empty()) return {};

    vector<vector<int>> ans;
    sort(v.begin(), v.end());

    for (int n = v.size(), i = 0; i < n && v[i] <= 0; ++i) {  // Vᵢ ≤ 0 because {0,0,0}
      if (i > 0 && v[i - 1] == v[i]) continue;

      for (int l = i + 1, r = n - 1; l < r;) {
        int s = v[i] + v[l] + v[r];
        if (!s) {
          ans.pb({v[i], v[l++], v[r--]});
          while (l < r && v[l - 1] == v[l]) ++l;
        } else if (s < 0)
          ++l;
        else
          --r;
      }
    }

    return ans;
  }
};
