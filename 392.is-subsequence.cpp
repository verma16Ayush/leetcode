/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(string s, string t, int m, int n)
    {
        if(m == 0) return 1;
        if(n == 0) return 0;
        if(s[m - 1] == t[n - 1]) return func(s, t, m - 1, n - 1);
        else return func(s, t, m, n - 1);
    }
    bool isSubsequence(string s, string t) 
    {
        return func(s, t, s.length(), t.length());
    }
};
// @lc code=end

