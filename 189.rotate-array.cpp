/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1) return;
        k = k % nums.size();
        reverse(&nums[0], &nums[nums.size() - k]);
        reverse(&nums[nums.size() - k], &nums[nums.size()]);
        reverse(nums.begin(), nums.end());        
    }
};
// @lc code=end

