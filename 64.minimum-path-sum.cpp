/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
// @lc code=start

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[201][201];
    int ChalAnswerBata(vector<vector<int>>& grid, int i, int j)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0) return dp[i][j] = grid[i][j];
        else if(i == 0) return dp[i][j] = grid[i][j] + ChalAnswerBata(grid, i, j - 1);
        else if(j == 0) return dp[i][j] = grid[i][j] + ChalAnswerBata(grid, i - 1, j);
        return dp[i][j] = grid[i][j] + min({ChalAnswerBata(grid, i - 1, j), ChalAnswerBata(grid, i, j - 1)});
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        memset(dp, -1, sizeof(dp));
        return(ChalAnswerBata(grid, grid.size() - 1, grid[0].size() - 1));
    }
};
// @lc code=end

