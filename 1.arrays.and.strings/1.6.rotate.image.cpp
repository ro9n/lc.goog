/**
 * @file 1.6.rotate.image
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
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) for(int j = i; j < n; ++j) swap(mat[i][j], mat[j][i]);
        for(int i = 0; i < n; ++i) for(int j = 0; j < n >> 1; ++j) swap(mat[i][j], mat[i][n - 1 - j]);
    }
};