/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        string str = "";
        char k = 'a';
        map<char, char> mp;
        for(int i = 'A'; i <= 'Z'; i++) mp[i] = k++;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z') str += s[i];
            else if(s[i] >= '0' && s[i] <= '9') str += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') str += mp[s[i]];
        }

        for(int i = 0; i < str.length() / 2; i++)
        {
            if(str[i] != str[str.length() - i - 1]) return false;
        }
        return true;
    }
};
// @lc code=end

