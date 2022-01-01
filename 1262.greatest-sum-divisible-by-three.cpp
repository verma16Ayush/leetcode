/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        for(int i : nums)
        {
            for(int j : vector<int>(dp))
            {
                dp[(j + i) % 3] = max(dp[(j + i) % 3], i + j); 
            }
        }
        return dp[0];
    }
    
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,2,3,4,4};
    cout << Solution().maxSumDivThree(a);
    return 0;
}