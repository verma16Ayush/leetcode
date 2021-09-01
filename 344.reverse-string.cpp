/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, en = s.size() - 1;
        while (i < en)
        {
            swap(s[i++], s[en--]);
        }
    }
};
// @lc code=end

