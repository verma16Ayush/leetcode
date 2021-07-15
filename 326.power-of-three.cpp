/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        int mx = pow(3, (int)(log(INT32_MAX) / log(3)));
        if(n > 0 &&  mx % n == 0) return true;
        return false;
    }
};
// @lc code=end

