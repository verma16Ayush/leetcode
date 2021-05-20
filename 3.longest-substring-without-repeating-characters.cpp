/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.length() <= 1) return s.length();
        int i = 0;
        int j = 0;
        unordered_set<char> keyset;
        keyset.insert(s[j++]);
        int mx = 0;
        while(j < s.length())
        {
            char c = s[j];
            while(keyset.find(c) != keyset.end())
            {
                keyset.erase(s[i++]);
            }
            keyset.insert(c);
            j++;
            mx = max((int)keyset.size(), mx);
        }
        return mx;
    }
};
// @lc code=end

