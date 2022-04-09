/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, en = nums.size() - 1;
        // int mid;
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(nums[mid] == target)
                return mid;
            if(target > nums[mid])
                st = mid + 1;
            else
                en = mid - 1;
        }
        return st;
    }
};
// @lc code=end

