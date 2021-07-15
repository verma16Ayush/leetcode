/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = 0;
        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' ')i--;
        for(i; i >= 0 && s[i] != ' '; i--)
        {
            k++;
        }
        return k;
    }
};
// @lc code=end

