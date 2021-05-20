/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=star
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int water = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j)
        {
            int h = min(height[i], height[j]);
            water = max(water, h * (j - i));
            while(i < j && height[i] <= h) i++;
            while(i < j && height[j] <= h) j--;
        }

        return water;
    }
};
// @lc code=end

