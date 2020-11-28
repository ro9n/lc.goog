/**
 * @file 3.12.most.stones.removed.with.same.row.column
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday November 10 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e4;
int d[mxn];

class Solution {
 public:
  int removeStones(vector<vector<int>>& S) {
    int n = S.size();

    unordered_set<int> r[mxn], c[mxn];
    for (int i = 0; i < n; ++i) r[S[i][0]].insert(i), c[S[i][1]].insert(i);
    for (int i = 0; i < n; ++i) d[i] = r[S[i][0]].size() + c[S[i][1]].size();

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int a, int b) {
      return d[a] < d[b];
    });

    int C = 0;
    for (int i = 0; i < n; ++i) {
      int ii = indices[i], rr = S[ii][0], cc = S[ii][1];
      if (r[rr].size() + c[cc].size() > 2) ++C, r[rr].erase(ii), c[cc].erase(ii);
    }
    return C;
  }
};