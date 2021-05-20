/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int i = 0;
        int j = 31;
        while(i < 16)
        {
            if((n & (1 << i)) == 0 && (n & (1 << j)) != 0 || (n & (1 << i)) != 0 && (n & (1 << j)) == 0)
            {
                n = n ^ (1 << i);
                n = n ^ (1 << j);
            }
            i++;
            j--;
        }
        return n;
    }
};
// @lc code=end

