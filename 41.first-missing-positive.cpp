/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int correctPos = nums[i] - 1;
            while(correctPos >= 0  && correctPos < n && nums[correctPos] != correctPos + 1)
                swap(nums[i], nums[correctPos]);
        }

        for(int i = 0; i < n; i++)
            if(nums[i] - 1 != i) return i + 1;
        return n + 1;
    }
};
// @lc code=end

