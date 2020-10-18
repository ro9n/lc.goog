/**
 * @file 1.20.kth.largest.element.in.array
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> q;
    for (auto x : nums) {
      q.push(-x);
      if (q.size() > k) q.pop();
    }
    return -q.top();
  }
};