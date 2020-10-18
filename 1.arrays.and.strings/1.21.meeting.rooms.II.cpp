/**
 * @file 1.21.meeting.rooms.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minMeetingRooms(vector<vector<int>> &x) {
    sort(x.begin(), x.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];  // start time asc
    });

    priority_queue<int> q;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
      if (q.empty()) q.push(-x[i][1]);
      else if (-q.top() > x[i][0])
        q.push(-x[i][1]);
      else
        q.pop(), q.push(-x[i][1]);
    }

    return q.size();
  }
};