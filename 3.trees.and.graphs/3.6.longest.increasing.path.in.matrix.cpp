/**
 * @file 3.6.longest.increasing.path.in.matrix
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

class Solution {
 public:
  // O(mn) Each vertex/cell will be calculated once and only once, 
  // and each edge will be visited once and only once. 
  // The total time complexity is then O(V+E).  
  // V is the total number of vertices and E is the total number of edges. 
  // In our problem, O(V)=O(mn), O(E)=O(4V)=O(mn).
  int longestIncreasingPath(vector<vector<int>>& mat) {
    if (mat.empty()) return 0;
    int n = mat.size(), m = mat[0].size(), dp[n][m], best = 0, vis[n][m];

    memset(dp, -1, sizeof dp);
    memset(vis, 0, sizeof vis);

    function<int(int, int)> dfs = [&](int i, int j) {
      int& ans = dp[i][j];
      if (~ans) return ans;
      int depth = 0;
      for (int d = 0; d < 4; ++d) {
        int y = i + dy[d], x = j + dx[d];
        if (y < 0 || y >= n || x < 0 || x >= m || vis[y][x] || mat[y][x] <= mat[i][j]) continue;
        vis[y][x] = 1;
        depth = max(depth, dfs(y, x));
        vis[y][x] = 0;
      }
      ans = depth + 1;
      return ans;
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        best = max(best, dfs(i, j));
      }
    }

    return best;
  }
};
