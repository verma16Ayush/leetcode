/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        // return help(nums, nums.size(), INT32_MAX);
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i]) dp[j] = max(1 + dp[i], dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
        
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {0, 1, 0, 3, 2, 3};
    cout << Solution().lengthOfLIS(a);
    return 0;
}
