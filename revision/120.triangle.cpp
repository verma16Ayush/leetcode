/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    vector<vector<int>> dp;
public:
    int help(vector<vector<int>>& tri, int i, int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i >= tri.size())
            return dp[i][j] = 0;
        return dp[i][j] = tri[i][j] + min(help(tri, i + 1, j), help(tri, i + 1, j + 1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // reverse(triangle.begin(), triangle.end());
        dp = vector<vector<int>>(triangle.size() + 1, vector<int>(triangle.size() + 1, -1));
        return help(triangle, 0, 0);
        
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
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    cout << Solution().minimumTotal(a) << endl;
    return 0;
}

