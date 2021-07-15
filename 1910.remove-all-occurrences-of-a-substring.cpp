/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0, j = 0;
        string ans;
        while(i + part.length() < s.length())        
        {
            ans.push_back(s[i]);
            if(ans.back() == part[j]) j++;
            else if(ans.back() != part[j]) j = 0;
            if(j == part.size())
            {
                j = 0;
                for(int k = 0; k < part.size(); k++) ans.pop_back();
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string a = "daabcbaabcbc";
    string b = "abc";

    Solution sol;
    cout << sol.removeOccurrences(a, b) << endl;
    return 0;
}