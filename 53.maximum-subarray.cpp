/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[(int)1e5] = {0}; // declare dp array for maximum size
    int GetMaxSub(const vector<int>& nums, int n)
    {
        if(n == 1) return dp[n - 1] = nums[n - 1]; // base case
        return dp[n - 1] = max(nums[n - 1], nums[n - 1] + GetMaxSub(nums, n - 1)); //recursive case
    }
    
    int maxSubArray(vector<int>& nums) 
    {
        GetMaxSub(nums, nums.size());
        return *max_element(dp, dp + nums.size()); //return the maximum of all dp[i]
    }
    
};

// @lc code=end

