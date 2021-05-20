/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            k = k ^ nums[i];
            k = k ^ i;
        }
        k = k ^ nums.size();
        return k;
    }
};
// @lc code=end

