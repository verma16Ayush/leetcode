/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) 
    {
        int mn = nums.size();
        for(int i = 0; i < nums.size(); i++)    
        {
            if(nums[i] == target) mn = min(mn, abs(i - start)); 
        }
        return mn;
    }
};
// @lc code=end

