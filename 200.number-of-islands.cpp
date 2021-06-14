/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir;
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return;
        if(grid[i][j] == '1')
        {
            grid[i][j] = '*';
            for(auto d : dir)
            {
                dfs(grid, i + d.first, j + d.second);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1') 
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end

