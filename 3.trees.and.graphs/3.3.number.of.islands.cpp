/**
 * @file 3.3.number.of.islands
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void dfs(vector<vector<char>> &g, int i, int j) {
  int n = g.size(), m = g[0].size();
  for (int d = 0; d < 4; ++d) {
    int y = i + dy[d], x = j + dx[d];
    if (y < 0 || y >= n || x < 0 || x >= m || g[y][x] != '1') continue;
    g[y][x] = '0';
    dfs(g, y, x);
  }
}

class Solution {
 public:
  int numIslands(vector<vector<char>> &g) {
    if (g.empty()) return 0;
    int n = g.size(), m = g[0].size(), c = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == '1')
          ++c, dfs(g, i, j);
      }
    }

    return c;
  }
};
