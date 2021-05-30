/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int i = 1;
        for(i; i < a.size(); i++)
        {
            a[0] = a[0] ^ a[i];
        }
        return a[0];
    }
};
// @lc code=end

