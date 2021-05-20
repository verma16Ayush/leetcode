/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
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
        if(nums.size() == 1) return nums[0];
        memset(dp, -1, sizeof(dp));
        int ans1 = Count(nums, nums.size() - 1);
        vector<int> nums2(nums.size() - 1);
        for(int i = 1; i < nums.size(); i++)
        {
            nums2[i - 1] = nums[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans2 = Count(nums2, nums2.size());
        return max(ans1, ans2);
    }
};
// @lc code=end

