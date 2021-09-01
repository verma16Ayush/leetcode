/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c0 = 0, c1 = 0;
        for(char c : s)
            c == '0' ? c0++ : c1++;
        int pre0 = 0, pre1 = 0;
        int ans = min(c0, c1);
        for(char c : s)
        {
            c == '0' ? pre0++ : pre1++;
            ans = min(ans, pre1 + c0 - pre0);
        }
        return ans;
    }
};
// @lc code=end

