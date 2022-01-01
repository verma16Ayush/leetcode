/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dp;
    int help(vector<vector<int>>& a, int n, int i)
    {
        if(dp[n] != -1)
            return dp[n];
        if(n == 0) 
            return dp[n] = 0;
        if(i == 0)
            return dp[n] = a[n - 1][i] + help(a, n - 1, i);
        return dp[n] = min(a[n - 1][i] + help(a, n - 1, i), a[n - 1][i - 1] + help(a, n - 1, i - 1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = vector<int>(triangle.size() + 1, -1);
        help(triangle, triangle.size(), triangle[triangle.size() - 1].size() - 1);
        return dp[triangle.size()];
    }

};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << Solution().minimumTotal(a);
    return 0;
}