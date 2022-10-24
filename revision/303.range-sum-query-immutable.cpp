/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {
public:
    vector<int> ps;
    NumArray(vector<int>& nums) {
        ps = vector<int>(nums.size());
        ps[0] = nums[0];
        for(int i = 1; i < ps.size(); i++)
        {
            ps[i] = nums[i];
            ps[i] += ps[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return ps[right];
        return ps[right] - ps[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

