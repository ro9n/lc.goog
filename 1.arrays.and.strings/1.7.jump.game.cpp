/**
 * @file 1.7.jump.game
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 15 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size(), r = n - 1;

    for (int i = n - 1; i >= 0; --i) {
      if (i + nums[i] >= r) r = i;
    }
    
    return !r;
  }
};
