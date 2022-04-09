/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int st = 0, en = s.size() - 1;
        while(st < en)
        {
            if(s[st] != s[en])
            {
                string delete_st = s.substr(0, st).append(s.substr(st + 1, s.size() - 1 - (st + 1) + 1));
                string delete_en = s.substr(0, en).append(s.substr(en + 1, s.size() - 1 - (en + 1) + 1));
                return IsPalin(delete_en) || IsPalin(delete_st);
            }
            st++;
            en--;
        }
        return true;
    }
    bool IsPalin(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout << "hello world" << endl;
    return 0;
}

