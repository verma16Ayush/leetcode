/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int IsValid(int i, int j, vector<vector<int>>& grd)
    {
        if(i >= 0 && j >= 0 && i < grd.size() && j < grd[0].size())
            return 1;
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    mat[i][j] = 0;
                    q.push({i, j});
                }
                else if(grid[i][j] == 0) 
                    mat[i][j] = -1;
                else
                    mat[i][j] = INT32_MAX;
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(q.size())
        {
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;

            for(auto d : dir)
            {
                if(!IsValid(i + d.first, j + d.second, grid) || grid[i + d.first][j + d.second] == 0)
                    continue;
                if(1 + mat[i][j] < mat[i + d.first][j + d.second])
                {
                    mat[i + d.first][j + d.second] = 1 + mat[i][j];
                    q.push({i + d.first, j + d.second});
                }
            }
        }
        int mx = 0;
        for(auto& i : mat)
            mx = max(mx, *max_element(i.begin(), i.end()));
        return mx == INT32_MAX ? -1 : mx;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a {
        {2,1,1},
        {0,1,1},
        {1,0,1},
    };
    cout << Solution().orangesRotting(a);
    return 0;
}