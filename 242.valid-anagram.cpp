/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length()) return 0;
        vector<int> sm(26);
        vector<int> tm(26);
        for(char i = 'a'; i <= 'z'; i++) sm[i - 'a'] = 0, tm[i - 'a'] = 0;

        for(int i = 0; i < s.length(); i++) sm[s[i] - 'a']++;
        for(int i = 0; i < t.length(); i++) tm[t[i] - 'a']++;

        for(int i = 0; i < 26; i++)
        {
            if(sm[i] != tm[i]) return 0;
        }
        return 1;
    }
};
// @lc code=end

