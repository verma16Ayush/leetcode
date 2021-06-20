/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    vector<pair<int, int>> dir;
    
    int dfs(vector<vector<int>>& grid, int i, int j, int s, int ts)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) return 0;
        if(grid[i][j] == 2) return s == ts ? 1 : 0;
        int ans = 0;
        for(auto d : dir)
        {
            grid[i][j] = -1; 
            ans += dfs(grid, i + d.first, j + d.second, s + 1, ts);
            grid[i][j] = 0;
        }
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        int si = 0, sj = 0, ts = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1) si = i, sj = j;
                if(grid[i][j] != -1) ts++;
            }
        }   
        return dfs(grid, si, sj, 1, ts);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    Solution sol;
    cout << sol.uniquePathsIII(a);
    return 0;
}

