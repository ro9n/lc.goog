/**
 * @file 3.1.btree.max.path.sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

const int INF = 1e5 + 7;

int best;

int dfs(TreeNode *h) {
  if (!h) return 0;
  int l = max(dfs(h->left), 0), r = max(dfs(h->right), 0);
  best = max(best, l + h->val + r);
  return h->val + max(l, r);
}

class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    best = -INF, dfs(root);
    return best;
  }
};