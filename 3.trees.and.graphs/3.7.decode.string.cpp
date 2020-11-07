/**
 * @file 3.7.decode.string
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 19 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string decodeString(const string &s) {
    int n = s.size();
    stack<int> ss;

    for (int i = 0; i < n; ++i) {
      if (s[i] != ']') ss.push(s[i] - 48);
      else {
        string s2;
        int rep = 0;
        while (isalpha((char)ss.top() + 48)) {
          s2 += (char)ss.top() + 48;
          ss.pop();
        }
        ss.pop();  // [

        int b = 1;
        while (!ss.empty() && isdigit((char)ss.top() + 48)) {
          rep += ss.top() * b;
          ss.pop(), b *= 10;
        }

        while (rep--) {
          for (int i = s2.size() - 1; i >= 0; --i) ss.push(s2[i] - 48);
        }
      }
    }

    string s3;
    while (!ss.empty()) {
      s3 += (char)ss.top() + 48;
      ss.pop();
    }
    reverse(s3.begin(), s3.end());
    return s3;
  }
};
