/**
 * @file 1.4.next.permutation
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday October 14 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    // narayan pandit's algo from 14ᵗʰ century
    int n = nums.size(), l = n - 2;
    while (~l && nums[l] >= nums[l + 1]) --l;
    if (l < 0) reverse(nums.begin(), nums.end());  // max permu, reset to min
    else {
      int r = n - 1;
      while (l < r && nums[l] >= nums[r]) --r;
      swap(nums[l], nums[r]);
      reverse(nums.begin() + l + 1, nums.end());
    }
  }
};
