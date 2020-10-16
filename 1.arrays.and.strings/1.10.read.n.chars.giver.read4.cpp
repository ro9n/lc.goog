/**
 * @file 1.10.read.n.chars.giver.read4
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int read4(char *buf);

class Solution {
  char buf4[4];
  int i4 = 0, n4 = 0;

 public:
  int read(char *buf, int n) {
    int i = 0;
    while (i < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buf4))))
      buf[i++] = buf4[i4++];
    return i;
  }
};