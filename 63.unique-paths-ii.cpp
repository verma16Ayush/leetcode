/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0] == 1) return 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < obstacleGrid.size(); i++) 
        {
            for(int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i < obstacleGrid.size(); i++)
        {
            if(dp[i][0] == 0) continue;
            dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i < obstacleGrid[0].size(); i++)
        {
            if(dp[0][i] == 0) continue;
            dp[0][i] = dp[0][i - 1];
        }

        for(int i = 1; i < obstacleGrid.size(); i++)
        {
            for(int j = 1; j < obstacleGrid[0].size(); j++)
            {
                if(dp[i][j] == 0) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end

