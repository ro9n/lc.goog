/**
 * @file 1.17.valid.parentheses
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> m {
  { '(', ')' },
  { '{', '}' },
  { '[', ']' }
};

inline bool open(char c) {
  return c == '(' || c == '{' || c == '[';
}
class Solution {
 public:
  bool isValid(string s) {
    stack<char> S;
    for(auto c: s) {
      if (open(c)) {
        S.push(m[c]);
      } else {
        if (S.empty()) return 0;
        else if (S.top() != c) return 0;
        else S.pop();
      }
    }

    return S.empty();
  }
};
