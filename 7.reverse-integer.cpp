/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    ll reverse(ll x) {
        int ng = x < 0 ? -1 : 1;
        string s = to_string(abs(x));
        std::reverse(s.begin(), s.end());
        try
        {
            return ng * stoi(s);
        }
        catch(const std::exception& e)
        {
            return 0;
        }
    }
};
// @lc code=end