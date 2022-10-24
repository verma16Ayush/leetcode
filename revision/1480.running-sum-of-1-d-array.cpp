/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ps(nums.size());
        ps[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            ps[i] = nums[i];
            ps[i] += ps[i - 1];
        }
        return ps;
    }
};
// @lc code=end

