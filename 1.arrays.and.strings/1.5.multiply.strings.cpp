/**
 * @file 1.5.multiply.strings
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday October 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string multiply(string u, string v) {
    int n = u.size(), m = v.size();
    string product(n + m, '0');

    function<void(int, int)> add = [&product, &add](int i, int k) {
      int tmp, sum, carry;
      tmp = product[i] - '0';
      sum = tmp + k;
      carry = sum / 10;
      sum %= 10;
      product[i] = (char)sum + 48;
      if (carry) add(i - 1, carry);
    };

    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        add(i + j + 1, (u[i] - '0') * (v[j] - '0'));
      }
    }

    int pad = 0; while(pad < n + m - 1 && product[pad] == '0') ++pad;
    return product.substr(pad);
  }
};