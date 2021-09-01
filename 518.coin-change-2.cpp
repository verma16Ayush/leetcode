/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[301][5001]; // dp[size][amount]
    int Help(vector<int>& a, int n, int target)
    {
        if(dp[n][target] != -1) return dp[n][target];
        if(target == 0) return dp[n][target] = 1;
        if(n == 0) return dp[n][target] = 0;
        
        if(a[n - 1] <= target)
            dp[n][target] = Help(a, n, target - a[n - 1]) + Help(a, n - 1, target);
        else
            dp[n][target] = Help(a, n - 1, target);
        return dp[n][target];

    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        Help(coins, coins.size(), amount);
        return dp[coins.size()][amount];
    }
};
// @lc code=end

