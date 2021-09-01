/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dp;
    bool increasingTriplet(vector<int>& nums) {
        dp = vector<int>(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i]) dp[j] = max(1 + dp[i], dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end()) >= 3;
    }
};
// @lc code=end

