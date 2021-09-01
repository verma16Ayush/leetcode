/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string st;
        string ans;
        while(ss >> st)
        {
            reverse(st.begin(), st.end());
            ans.append(st);
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
// @lc code=end

