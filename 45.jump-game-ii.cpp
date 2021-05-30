/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), INT32_MAX);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j <= nums[i]; j++)
            {
                int k = i + j >= nums.size() - 1 ? nums.size() - 1 : i + j;
                dp[k] = min(dp[k], 1 + dp[i]);
            }
        }
        return dp[dp.size() - 1];
    }
};
// @lc code=end

