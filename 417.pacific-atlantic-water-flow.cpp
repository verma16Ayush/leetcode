/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct Flows
{
    int toP;
    int toA;
    Flows(int a = -1, int p = -1)
    {
        toA = a;
        toP = p;
    }
};

class Solution 
{
public:
    int dp[300][300][2]; // dp[r][c][0] = atlantic, dp[r][c][1] = pacific
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfsToA(vector<vector<int>>& heights, int R, int C, int r, int c)
    {
        if(r >= R - 1 || c >= C - 1) return dp[r][c][0] = 1;
        if(dp[r][c][0] != -1) return dp[r][c][0];
        if(heights[r][c] == -1) return dp[r][c][0] = 0;
        int temp = heights[r][c];
        heights[r][c] = -1;
        for(auto d : dir)
        {
            if(r + d.first >= R || c + d.second >= C) return 1;
            else if(heights[r][c] >= temp) return dp[r][c][0] = dfsToA(heights, R, C, r + d.first, c + d.second);
        }
        heights[r][c] = temp;
        return dp[r][c][0];
    }
    int dfsToP(vector<vector<int>>& heights, int R, int C, int r, int c)
    {
        if(r <= 0 || c <= 0) return dp[r][c][1] = 1;
        if(dp[r][c][1] != -1) return dp[r][c][1];
        if(heights[r][c] == -1) return dp[r][c][1] = 0;
        int temp = heights[r][c];
        heights[r][c] = -1;
        for(auto d : dir)
        {
            if(r + d.first < 0 || c + d.second < 0) return 1;
            else if(heights[r][c] >= temp) return dp[r][c][1] = dfsToP(heights, R, C, r + d.first, c + d.second);
        }
        heights[r][c] = temp;
        return dp[r][c][1];
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int R = heights.size();
        int C = heights[0].size();
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                dfsToP(heights, R, C, i, j);
                dfsToA(heights, R, C, i, j);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(dp[i][j][0] && dp[i][j][1]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};

// @lc code=end

