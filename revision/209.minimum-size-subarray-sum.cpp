/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // vector<int> PrefixSum(vector<int>& a)
    // {
    //     vector<int> ps(a.size());
    //     ps[0] = a[0];
    //     for(int i = 1; i < a.size(); i++)
    //     {
    //         ps[i] = a[i];
    //         ps[i] += ps[i - 1];
    //     }
    //     return ps;
    // }
    int minSubArrayLen(int target, vector<int>& nums) {
        // auto ps = PrefixSum(nums);
        int l = 0, r = 0, n = nums.size();
        int minLen = INT32_MAX;
        int sum = 0;
        while(r < n)
        {
            sum += nums[r++];
            while(sum >= target)
            {
                minLen = min(minLen, r - l);
                sum -= nums[l++];
            }
        }
        return minLen == INT32_MAX ? 0 : minLen;
        
    }
};
// @lc code=end

