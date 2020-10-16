/**
 * @file 1.14.expressive.words
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

void count(const string &s, vector<int> &f, vector<int> &c) {
  int n = s.size();

  for (int i = 0; i < n; ++i) {
    if (!c.empty() && c.back() == s[i] - 97) continue;
    c.push_back(s[i] - 97);
    int ff = 1;
    while (i + 1 < n && s[i] == s[i + 1]) ++ff, ++i;
    f.push_back(ff);
  }
}

inline bool isexprs(const string &t, const string &p, const vector<int> &f2, const vector<int> &c2) {
  vector<int> f1, c1;
  count(p, f1, c1);

  int n = c1.size();
  if (n != c2.size()) return 0;

  for (int i = 0; i < n; ++i) {
    if (c1[i] != c2[i]) return 0;
    else if (f1[i] != f2[i] && f2[i] <= 2)
      return 0;
    else if (f1[i] > f2[i])
      return 0;  // "heeelllooo"["hellllo"]
  }
  return 1;
}

class Solution {
 public:
  int expressiveWords(string t, vector<string> &words) {
    int match = 0;
    vector<int> f2, c2;
    count(t, f2, c2);
    for (auto p : words) {
      if (p.size() > t.size()) continue;
      else if (isexprs(t, p, f2, c2))
        ++match;
    }
    return match;
  }
};
