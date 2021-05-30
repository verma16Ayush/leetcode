/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& a)
    {
        int lastReachable = a.size() - 1;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            if(i + a[i] >= lastReachable) lastReachable = i;
        }
        return lastReachable == 0;
    }
};
// @lc code=end

