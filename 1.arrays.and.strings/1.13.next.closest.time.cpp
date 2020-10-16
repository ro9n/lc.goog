/**
 * @file 1.13.next.closest.time
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
  // https://leetcode.com/problems/next-closest-time/discuss/171365/C%2B%2B-concise-solution-with-explanation-time-O(1)-space-O(1)-using-set-(100)
  // 1 Store the available <4 digit in set(sorted from minimum to maximum natrually);
  // 2 Start from end of the time string, replace it with the next larger number in the set. If available and a legal time(min < 60 && hh <24), return the result;
  // 3 Else replace it the smalleset number int the set , go to the next digit in the time string.
  //
  // Space is O(1), because <4 characters set; time is O(1), which goes through 4 characters in the string
  string nextClosestTime(string t) {
    set<char> s;
    for (auto c : t) {
      if (c == ':') continue;
      s.insert(c);
    }

    string res = t;
    for (int i = t.size() - 1; i >= 0; i--) {
      if (t[i] == ':') continue;
      auto it = s.find(t[i]);
      if (*it != *s.rbegin()) {  // not the largest number
        it++;                    // go to the next element
        res[i] = *it;
        if ((i > 2 && stoi(res.substr(3, 2)) < 60) || (i < 2 && stoi(res.substr(0, 2)) < 24))
          return res;
      }
      res[i] = *s.begin();  // take the smallest number
    }
    return res;
  }
};