/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    vector<pair<int, int>> dir;
    int dfs(vector<vector<int>>& mat, int i, int j)
    {
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == -1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        int mx = 0;
        int temp = mat[i][j];
        mat[i][j] = -1;
        for(auto d : dir)
        {
            if(i + d.first < 0 || j + d.second < 0 || i + d.first >= mat.size() || j + d.second >= mat[0].size()) continue;
            else if(mat[i + d.first][j + d.second] > temp)
            {
                mx = max(mx, dfs(mat, i + d.first, j + d.second));
            }
        }
        mat[i][j] = temp;
        dp[i][j] += mx;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // memset(&dp[0], -1, dp.size() * dp[0].size() * sizeof(int));
        int ans = 1;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                dfs(matrix, i, j);
                ans = max(ans, dp[i][j]);
            }
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
    vector<vector<int>> a = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    Solution sol;
    cout << sol.longestIncreasingPath(a);
    return 0;
}