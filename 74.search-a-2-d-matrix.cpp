/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0)
        {
            if(target > matrix[i][j])
                i++;
            else if(target < matrix[i][j])
                j--;
            else if(target == matrix[i][j])
                return 1;
        }
        return 0;
    }
};
// @lc code=end

