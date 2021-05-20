/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char, pair<string, char>> chk;
        chk['['] = {"open", '['};
        chk[']'] = {"close", '['};
        chk[')'] = {"close", '('};
        chk['('] = {"open", '('};
        chk['}'] = {"close", '{'};
        chk['{'] = {"open", '{'};
        stack<char> st;

        for(auto i : s)
        {
            if(chk[i].first == "open")
            {
                st.push(i);
            }
            else if(chk[i].first == "close")
            {
                if(st.empty()) return 0;
                else if(chk[i].second == st.top()) st.pop();
                else return 0;
            }
        }
        return st.empty();
    }
};
// @lc code=end
