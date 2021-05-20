/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int cntz = 0;
        int id = 0;
        int mp = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                id = i;
                cntz++;
                continue;
            }
            else mp *= nums[i];
        }
        if(cntz > 1) return vector<int> (nums.size());
        else if(cntz == 1)
        {
            vector<int> ans(nums.size());
            ans[id] = mp;
            return ans;
        }
        else
        {
            vector<int> ans(nums.size());
            for(int i = 0; i < nums.size(); i++)
            {
                ans[i] = mp / nums[i];
            }
            return ans;
        }
        return {};
    }
};
// @lc code=end

