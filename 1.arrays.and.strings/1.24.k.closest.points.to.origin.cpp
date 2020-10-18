/**
 * @file 1.24.k.closest.points.to.origin
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
  inline int d(const vi p) {
    return p[0] * p[0] + p[1] * p[1];
  }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vi>> q; vector<vi> ans;
        for(auto p: points) {
          q.push({d(p), p});
          if (q.size() > k) q.pop();
        }

        while(!q.empty()) ans.push_back(q.top().second), q.pop();
        return ans;
    }
};
