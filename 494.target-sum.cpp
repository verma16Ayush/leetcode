/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int dp[1001][21]; // dp[sum][size]
    int SubsetSum(vector<int>& a, int sum, int n)
    {
        if(dp[sum][n] != -1) 
            return dp[sum][n];
        if(sum == 0) 
            dp[sum][n] = 1;
        else if(n == 0) 
            dp[sum][n] = 0;
        else if(a[n - 1] <= sum) 
            dp[sum][n] = SubsetSum(a, sum - a[n - 1], n - 1) + SubsetSum(a, sum, n - 1);
        else dp[sum][n] = SubsetSum(a, sum, n - 1);
        return dp[sum][n];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        memset(dp, -1, sizeof(dp));
        int s1 = 0;
        int zeroCount = 0;
        vector<int> a;
        for(int i : nums) 
        {
            if(i == 0) zeroCount++;
            else a.push_back(i);
            s1 += i;
        }
        if((s1 + target) % 2) return 0;
        return SubsetSum(a, (s1 + target) / 2, a.size()) * pow(2, zeroCount);
        // return SubsetSum(nums, (s1 + target) / 2, nums.size());
    }
};
// @lc code=end


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> a = {1,1, 1, 1, 1, 0};
    memset(sol.dp, -1, sizeof(sol.dp));
    cout << sol.SubsetSum(a, 1, a.size()) << endl;
    return 0;
}
