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
    Solution() {
        dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    }

    int DFSHelper(vector<vector<int>>& grid, int i, int j)
    {
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return 0;
        if(grid[i][j] != 1)
            return 0;
        grid[i][j] = -1;
        
        int area = 1;
        for(auto d : dir)
        {
            area += DFSHelper(grid, i + d.first, j + d.second);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                maxArea = max(maxArea, DFSHelper(grid, i, j));
            }
        }
        return maxArea;
    }
};
// @lc code=end

