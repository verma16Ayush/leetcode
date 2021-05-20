/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int c = 0;
        while(n)
        {
            if(n & 1) c++;
            n = n >> 1;
        }
        return c;
    }
};
// @lc code=end

