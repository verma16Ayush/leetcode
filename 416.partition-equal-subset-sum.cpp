/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10001][201];
    bool SubsetSum(vector<int>& a, int sum, int n)
    {
        if(dp[sum][n] != -1) return dp[sum][n];
        if(sum == 0) return dp[sum][n] = 1;
        if(n == 0) return dp[sum][n] = 0;
        if(a[n - 1] <= sum) return dp[sum][n] = SubsetSum(a, sum - a[n - 1], n - 1) || SubsetSum(a, sum, n - 1);
        return dp[sum][n] = SubsetSum(a, sum, n - 1);
    }
    bool canPartition(vector<int>& nums) 
    {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2) return 0;
        return SubsetSum(nums, sum / 2, nums.size());
    }
};
// @lc code=end

