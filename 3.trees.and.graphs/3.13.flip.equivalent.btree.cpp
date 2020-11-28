/**
 * @file 3.13.flip.equivalent.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday November 27 2020
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

#define ld left
#define rd right

class Solution {
 public:
  bool flipEquiv(TreeNode *r1, TreeNode *r2) {
    if (!r1 || !r2) return r1 == r2;
    else
      return r1->val == r2->val && ((flipEquiv(r1->ld, r2->ld) && flipEquiv(r1->rd, r2->rd)) ||
                                    (flipEquiv(r1->ld, r2->rd) && flipEquiv(r1->rd, r2->ld)));
  }
};
