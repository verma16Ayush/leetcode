/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        int r = grid.size();
        int c = grid[0].size();

        // for(int i = 0; i < grid.size(); i++)
        // {
        //     for(int j = 0; j < grid[0].size(); j++)
        //     {
        //         ans[(i + k / c) % r][j + k % c] = grid[i][j];
        //     }
        // }
        for(int i = 0; i < r * c; i++)
        {
            int oi = i / c;
            int oj = i % c;

            int ni = (oi + (oj + k) / c) % r;
            int nj = (oj + k) % c;

            ans[ni][nj] = grid[oi][oj];
        }
        return ans;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    auto ans = Solution().shiftGrid(a, 1);
    for(auto i : ans)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
