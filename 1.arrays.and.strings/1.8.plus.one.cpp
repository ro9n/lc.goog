/**
 * @file 1.8.plus.one
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
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size(), c = 0;

    digits[n - 1] += 1;
    if (digits[n - 1] >= 10) digits[n - 1] -= 10, c = 1;

    for (int i = n - 2; i >= 0 && c; --i) {
      digits[i] += c;
      if (digits[i] >= 10) digits[i] -= 10, c = 1;
      else c = 0;
    }

    if (c) {
      vector<int> d;
      d.push_back(c);

      for(auto k: digits) d.push_back(k);
      return d;
    }

    return digits;
  }
};
