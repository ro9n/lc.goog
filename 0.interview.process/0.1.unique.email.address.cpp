/**
 * @file 0.1.unique.email.address
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 12 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

string h(string s) {
  string r;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') continue;
    if (s[i] == '+')
      while (s[i] != '@') ++i;
    if (s[i] == '@')
      while (i < n) r.pb(s[i++]);

    r.pb(s[i]);
  }

  return r;
}

class Solution {
 public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> s;
    for (auto e : emails) s.insert(h(e));
    return s.size();
  }
};
