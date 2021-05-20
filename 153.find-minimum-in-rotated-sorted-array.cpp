/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        return *min_element(nums.begin(), nums.end());
    }
};
// @lc code=end

