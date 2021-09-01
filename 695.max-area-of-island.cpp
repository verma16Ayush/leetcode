/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<pair<int, int>> dir;
    // int area;
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] == 0)
            return 0;
        int ans = 1;
        for(auto d : dir)
        {
            grid[i][j] = -1;
            ans += dfs(grid, i + d.first, j + d.second);
        }
        // grid[i][j] = 1;
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int aa = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    // area = 0;
                    // dfs(grid, i, j);
                    // aa = max(aa, area);
                    aa = max(aa, dfs(grid, i, j));
                }
                
            }
        }
        return aa;
    }
};
// @lc code=end

