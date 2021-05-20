/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int* dp;
    int Count(vector<int>& nums, int target, int size)
    {
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        if(size == 0) return dp[target] = 0;
        if(target == 0) return dp[target] = 1;
        int ans = 0;
        for(int i : nums)
        {
            ans += Count(nums, target - i, size);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) 
    {
        dp = new int[target + 1];
        memset(dp, -1, sizeof(int) * (target + 1));
        int ans = Count(nums, target, nums.size());
        delete[] dp;
        return ans;
    }
};
// @lc code=end

