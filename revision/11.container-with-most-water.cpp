/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxWater = 0;
        while(i < j)
        {
            int minH = min(height[i], height[j]);
            maxWater = max(minH * (j - i), maxWater);
            while(i < j && height[i] <= minH) i++;
            while(i < j && height[j] <= minH) j--;
        }
        return maxWater;
    }
};
// @lc code=end

