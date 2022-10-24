/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> PrefixSum(vector<int>& nums)
    {
        vector<int> ps(nums.size());
        ps[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            ps[i] = nums[i];
            ps[i] += ps[i - 1];
        }
        return ps;
    }

    int GetSum(vector<int>& ps, int l, int r)
    {
        return l == 0 ? ps[r] : ps[r] - ps[l - 1];
    }

    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int st = 0, en = 0;
        int maxSum = nums[0];
        // mp[nums[0]] = 1;
        vector<int> ps = PrefixSum(nums);

        while(st <= en && en < nums.size())
        {
            if(!mp[nums[en]])
            {
                maxSum = max(maxSum, GetSum(ps, st, en));
                mp[nums[en]]++;
                en++;
            }
            else
            {
                mp[nums[st]]--;
                st++;
            }
        }
        return maxSum;
    }
};
// @lc code=end

