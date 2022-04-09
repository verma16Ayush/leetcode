/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(is_sorted(nums.rbegin(), nums.rend()))
            reverse(nums.begin(), nums.end());
        else
        {
            int k = nums.size() - 1;
            while(k > 0 && nums[k - 1] > nums[k]) 
                k--;
            swap(nums[k - 1], nums[nums.size() - 1]);
            reverse(&nums[k], &nums[nums.size()]);
        }
        return;
    }
};
// @lc code=end

