/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> dir;
    Solution()
    {
        this->dir = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}};
    }
    void DFSHelper(vector<vector<char>> &grid, int i, int j)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return;
        if (grid[i][j] != '1')
            return;
        grid[i][j] = '*';
        for (auto d : dir)
            DFSHelper(grid, i + d.first, j + d.second);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int c = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    c++;
                    DFSHelper(grid, i, j);
                }
            }
        }
        return c;
    }
};
// @lc code=end
int32_t main()
{
#ifdef LOCAL_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> grid = { {'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'} };
    cout << Solution().numIslands(grid) << endl;
    return 0;
}
