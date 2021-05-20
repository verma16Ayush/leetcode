/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp[(int)3e4 + 2];
    bool Check(vector<int>& a, int n)
    {
        if(n == 1 && a[n - 1] > 0) dp[n] = 1;
        if()
    }
    bool canJump(vector<int>& nums) 
    {
        memset(dp, -1, sizeof(dp));
    }
};
// @lc code=end

