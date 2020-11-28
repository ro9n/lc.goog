/**
@file 3.11.robot.room.cleaner
@author Touhid Alam <taz.touhid@gmail.com>
 *
@date Monday November 09 2020
 *
@brief 
 */

#include <bits/stdc++.h>

using namespace std;

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
 public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the current cell.
  bool move();
  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();
  // Clean the current cell.
  void clean();
};

class Solution {
 public:
  void cleanRoom(Robot& r) {
    const int N = 200, dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};  // anticlk, choosing left: up left down right
    bool v[N << 1][N << 1];
    memset(v, 0, sizeof(v));

    function<void(int, int, int)> dfs = [&](int y, int x, int f) {
      r.clean();
      for (int d = 0; d < 4; ++d) {
        int dd = (f + d) % 4, yy = y + dy[dd], xx = x + dx[dd];
        if (!v[yy + N][xx + N] && r.move()) v[yy + N][xx + N] = 1, dfs(yy, xx, dd), r.turnLeft(), r.turnLeft(), r.move(), r.turnLeft(), r.turnLeft();
        r.turnLeft();
      }
    };

    v[N][N] = 1, dfs(0, 0, 0);
  }
};

/*
class Solution {
 public:
  void cleanRoom(Robot& r) {
    const int dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};  // anticlk, choosing left: up left down right
    set<pair<int, int>> v;

    function<void(int, int, int)> dfs = [&](int y, int x, int f) {
      r.clean();
      for (int d = 0; d < 4; ++d) {
        int dd = (f + d) % 4, yy = y + dy[dd], xx = x + dx[dd];
        if (!v.count({yy, xx}) && r.move()) v.insert({yy, xx}), dfs(yy, xx, dd), r.turnLeft(), r.turnLeft(), r.move(), r.turnLeft(), r.turnLeft();
        r.turnLeft();
      }
    };

    v.insert({0, 0}), dfs(0, 0, 0);
  }
};
*/
