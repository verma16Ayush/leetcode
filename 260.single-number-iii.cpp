/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int> a;
        vector<int> b;
        int xy = 0;
        for(int i : nums) xy ^= i;
        int k = 0;
        for(int i = 0; i < 32; i++)
        {
            if(xy & (1 << i))
            {
                k = 1 << i;
                break;
            }
        }

        for(int i : nums)
        {
            if(k & i) a.push_back(i);
            else b.push_back(i);
        }

        int x = 0;
        int y = 0;
        for(int i : a) x ^= i;
        for(int i : a=b) y ^= i;

        return {x, y};

    }
};
// @lc code=end

