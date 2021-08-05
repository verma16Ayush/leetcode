/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int> left(height.size()), right(height.size());
        int n = height.size();
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++) left[i] = max(left[i - 1], height[i]);
        for(int i = n - 2; i >= 0; i--) right[i] = max(height[i], right[i + 1]);
    
        int wt = 0;
        for(int i = 0; i < n; i++) wt += min(left[i], right[i]) - height[i];
        return wt;
    }
};
// @lc code=end

