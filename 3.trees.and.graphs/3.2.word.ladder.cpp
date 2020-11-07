/**
 * @file 3.2.word.ladder
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

class Solution {
 public:
  int ladderLength(string b, string e, vector<string>& w) {
    queue<pair<int, string>> q; q.push({1, b});
    unordered_set<string> s(w.begin(), w.end());

    while (!q.empty()) {
      auto u = q.front(); q.pop();
      int n = u.ss.size();

      for (int i = 0; i < n; ++i) {
        int k = u.ss[i] - 97;
        for (int j = 0; j < 26; ++j) {
          if (j == k) continue;
          u.ss[i] = (char)j + 97;
          if (s.count(u.ss)) {
            if (u.ss == e) return u.ff + 1;
            else {
              s.erase(u.ss);
              q.push({u.ff + 1, u.ss});
            }
          }
        }
        u.ss[i] = (char)k + 97;
      }
    }

    return 0;
  }
};
