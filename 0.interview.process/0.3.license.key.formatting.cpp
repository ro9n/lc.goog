/**
 * @file 0.3.license.key.formatting
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday October 13 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = S.size(); string s;

        for(int i = n - 1, j = 0; i >= 0; --i) {
          if (S[i] == '-') continue;
          s += toupper(S[i]), ++j;
          if (j == K) s += '-', j = 0;
        }

        if (s.back() == '-') s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
};
