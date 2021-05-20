/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101];
    int Count(vector<int>& nums, int sz)
    {
        if(sz < 0) return 0;
        if(dp[sz] != -1) return dp[sz];
        if(sz == 0) return dp[sz] = 0;
        return dp[sz] = max(nums[sz - 1] + Count(nums, sz - 2), Count(nums, sz - 1));
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return Count(nums, nums.size());
    }
};
// @lc code=end

