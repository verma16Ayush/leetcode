/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dp;
    int help(int n)
    {
        if(dp[n] != -1)
            return dp[n];
        if(n == 0)
            return dp[n] = 1;
        if(n >= 2)
            return dp[n] = help(n - 1) + help(n - 2);
        return dp[n] = help(n - 1);
    }
    int climbStairs(int n) {
        dp = vector<int>(n + 1, -1);
        help(n);
        return dp[n];
    }
};
// @lc code=end

