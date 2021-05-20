/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> dp;
    pair<int, int> AnswerBata(const vector<int>& nums, int n)
    {
        if(dp[n - 1].first != -1 || dp[n - 1].second != -1) return dp[n - 1];
        if(n == 1)
        {
            dp[n - 1].first = nums[n - 1];
            dp[n - 1].second = nums[n - 1];
            return dp[n - 1];
        }
        dp[n - 1].first = max({nums[n - 1], nums[n - 1] * AnswerBata(nums, n - 1).first, nums[n - 1] * AnswerBata(nums, n - 1).second});
        dp[n - 1].second = min({nums[n - 1], nums[n - 1] * AnswerBata(nums, n - 1).first, nums[n - 1] * AnswerBata(nums, n - 1).second});
        return dp[n - 1];
    }
    int maxProduct(vector<int>& nums) 
    {
        dp = vector<pair<int, int>>(nums.size(), {-1, -1});
        AnswerBata(nums, nums.size());
        int mxp = dp[0].first;
        for(int i = 0; i < dp.size(); i++)
        {
            mxp = max(dp[i].first, mxp);
        }
        return mxp;
    }
};
// @lc code=end

