/**
 * @file 3.8.evaluate.division
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 19 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

unordered_map<string, vector<pair<string, double>>> m;
unordered_set<string> vis;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
    int n = v.size();
    m.clear(), vis.clear();
    vector<double> ans;

    function<double(string, string)> dfs = [&](string u, string k) -> double {
      if (u == k) return 1;
      vis.insert(u);

      for (auto v : m[u]) {
        if (!vis.count(v.ff)) {
          double ans = dfs(v.ff, k);
          if (ans != -1) {
            vis.erase(u);
            return ans * v.ss;
          }
        }
      }

      vis.erase(u);
      return -1;
    };

    for (int i = 0; i < n; i++) {
      m[eq[i][0]].push_back({eq[i][1], v[i]});
      m[eq[i][1]].push_back({eq[i][0], 1 / v[i]});
    }

    for (auto p : q) {
      if (!m.count(p[0]) || !m.count(p[1])) ans.push_back(-1.f);
      else
        ans.push_back(dfs(p[0], p[1]));
    }

    return ans;
  }
};
