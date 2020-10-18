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

#define pb     push_back
#define all(v) v.begin(), v.end()
#define ff     first
#define ss     second

typedef pair<int, int> ii;

class Solution {
 public:
  string findReplaceString(string S, vector<int>& I, vector<string>& F, vector<string>& R) {
    int n = I.size();

    vector<ii> II;

    for (int i = 0; i < n; ++i) {
      if (S.substr(I[i], F[i].size()) == F[i]) II.pb({I[i], i});
    }

    sort(all(II), [](ii a, ii b) { return a.ff < b.ff; });

    string s;
    int n2 = S.size(), n3 = II.size();

    for (int i = n2 - 1, j = n3 - 1; i >= 0; --i) {
      if (~j) {
        int l = I[II[j].ss], r = l + F[II[j].ss].size() - 1;
        if (i > r) s += S[i];
        else {
          i = l; // keep one index to the right because --i at the for loop definition
          for (int k = R[II[j].ss].size() - 1; k >= 0; --k) {
            s += R[II[j].ss][k];
          }
          --j;
        }
      } else s += S[i];
    }

    reverse(all(s));

    return s;
  }
};