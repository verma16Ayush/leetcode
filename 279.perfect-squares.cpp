/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10001][101]; // dp[sum][size]
    int SubsetSum(vector<int>& a, int target, int n)
    {
        if(dp[target][n] != -1) return dp[target][n];
        if(target == 0) return dp[target][n] = 0;
        if(n == 0) return dp[target][n] = (int)1e8;
        if(a[n - 1] <= target) 
        {
            int k = 1 + SubsetSum(a, target - a[n - 1], n);
            int l = SubsetSum(a, target, n - 1);
            return dp[target][n] = min(k, l);
        }
        return dp[target][n] = SubsetSum(a, target, n - 1);
    }
    int numSquares(int n) {
        vector<int> a(100);
        for(int i = 1; i <= a.size(); i++)
        {
            a[i - 1] = i * i;
        }
        memset(dp, -1, sizeof(dp));
        SubsetSum(a, n, a.size());
        return dp[n][a.size()];
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    cout << sol.numSquares(144) << endl;
    return 0;
}
