/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> merged;
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }

        while(i < m)
            merged.push_back(nums1[i++]);
        while(j < n)
            merged.push_back(nums2[j++]);

        nums1 = merged;
    }
};
// @lc code=end

