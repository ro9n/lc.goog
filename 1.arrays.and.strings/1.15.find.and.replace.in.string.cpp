/**
 * @file 1.15.find.and.replace.in.string
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
  string findReplaceString(string S, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    int n = indices.size(), l = 0;
    vector<int> accept(n);
    for(int i = 0; i < n; ++i) {
      accept[i] = S.substr(indices[i], sources[indices[i]].size()) == sources[i];
    }

    string s;
    for(int r = 0, i = 0; i < n; ++i) {
      if (!accept[i]) continue;
      r = indices[i] - 1;
      s += S.substr(l, r - l + 1);
      s += targets[i];
      l = indices[i] + sources[i].size();
    }
    s += S.substr(l);

    return s;
  }
};