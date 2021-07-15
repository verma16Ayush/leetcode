/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp2, mp1;
        for(int i = 0; i < s.length(); i++)
        {
            if(mp1.find(t[i]) == mp1.end() && mp2.find(s[i]) == mp2.end()) mp1[t[i]] = s[i], mp2[s[i]] = t[i];
            else if(mp1[t[i]] != s[i] || mp2[s[i]] != t[i]) return false;
        }
        return true;
    }
};
// @lc code=end

