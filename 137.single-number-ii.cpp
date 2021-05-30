/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> a(32, 0);
        for(int i : nums)
        {
            for(int j = 0; j < 32; j++)
            {
                if((1 << j) & i) a[j]++;
                a[j] = a[j] % 3;
            }
        }

        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if(a[i]) ans += (1 << i);
        }
        return ans;
    }
};
// @lc code=end

