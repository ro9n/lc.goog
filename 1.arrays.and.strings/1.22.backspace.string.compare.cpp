/**
 * @file 1.22.backspace.string.compare
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

inline string h(const string &s) {
  string r;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '#' && !r.empty()) r.pop_back();
    else if (s[i] != '#')
      r.push_back(s[i]);
  }

  return r;
}

class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    return !h(S).compare(h(T));
  }
};
