/**
 * @file 3.4.course.schedule.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<int> g[n], ans, vis(n);

    for (int i = 0; i < pre.size(); ++i) {
      g[pre[i][1]].push_back(pre[i][0]);
    }

    function<bool(int)> dfs = [&](int u) {
      vis[u] = 1;
      for (int v : g[u]) {
        if (vis[v] == 1) return 0;
        else if(!vis[v]) if(!dfs(v)) return 0;
      }
      ans.emplace_back(u);
      vis[u] = 2;
      return 1;
    };

    for (int i = 0; i < n; ++i) {
      if (!vis[i]) if (!dfs(i)) return {};
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
