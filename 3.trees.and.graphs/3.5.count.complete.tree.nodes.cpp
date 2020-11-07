/**
 * @file 3.5.count.complete.tree.nodes
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ld left
#define rd right

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int countNodes(TreeNode *r) {
    int ans = 0;
    if (!r) return ans;
    queue<TreeNode *> q; q.push(r);

    while(!q.empty()) {
        auto f = q.front(); q.pop();
        ++ans;
        
        if (f->rd && !f->ld) continue;
        
        if (f->ld) q.push(f->ld);
        if (f->rd) q.push(f->rd);
    }

    return ans;
  }
};
