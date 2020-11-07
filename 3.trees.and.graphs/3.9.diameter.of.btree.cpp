/**
 * @file 3.9.diameter.of.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 19 2020
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

int best;

int dfs(TreeNode *r) {
  if (!r) return 0;
  int left = dfs(r->ld), right = dfs(r->rd);
  best = max(best, left + right);
  return 1 + max(left, right);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        best = 0, dfs(root);
        return best;
    }
};

