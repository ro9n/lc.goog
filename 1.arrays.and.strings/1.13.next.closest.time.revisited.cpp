/**
 * @file 1.13.next.closest.time.revisited
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
  string nextClosestTime(string t) {
    set<int> s{t[0] - '0', t[1] - '0', t[3] - '0', t[4] - '0'};
    string ans = t;

    for (int n = t.size(), i = n - 1; i >= 0; --i) {
      if (i == 2) continue;  // :
      auto it = s.upper_bound(t[i] - '0');
      if (it != s.end()) {
        ans[i] = (char)(*it) + 48;
        if ((i > 2 && stoi(ans.substr(3, 2)) < 60) ||
            (i < 2 && stoi(ans.substr(0, 2)) < 24)) {
          return ans;
        }
      }
      ans[i] = (char)*s.begin() + 48;
    }

    return ans;
  }
};
