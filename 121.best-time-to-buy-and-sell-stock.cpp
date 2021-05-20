/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
        vector<pair<int, int>> maxStack;
        int mx = INT32_MIN;
        int mxp = INT32_MIN;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            mx = max(mx, a[i]);
            maxStack.push_back({a[i], mx});
            mxp = max(mxp, maxStack.back().second - maxStack.back().first);
        }
        return mxp;
    }
};
// @lc code=end

