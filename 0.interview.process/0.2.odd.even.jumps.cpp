/**
 * @file 0.2.odd.even.jumps
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 12 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

class Solution {
 public:
  int oddEvenJumps(vector<int>& A) {
    int n = A.size(), odd[n], evn[n], ans = 1;
    map<int, int> m;

    odd[n - 1] = evn[n - 1] = 1;
    m[A[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
      map<int, int>::iterator nxt_odd = m.lower_bound(A[i]), nxt_evn = m.upper_bound(A[i]);
      ans += odd[i] = A[i] <= nxt_odd->ff && evn[nxt_odd->ss];
      if (nxt_evn != m.begin()) nxt_evn = prev(nxt_evn);
      evn[i] = A[i] >= nxt_evn->ff && odd[nxt_evn->ss];
      m[A[i]] = i;
    }
    return ans;
  }
};

