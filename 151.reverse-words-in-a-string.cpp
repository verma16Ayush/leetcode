/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string st;
        vector<string> ans;
        while (ss >> st)
        {
            ans.push_back(st);
        }
        reverse(ans.begin(), ans.end());
        st = "";
        for(string sss : ans)        
        {
            st.append(sss);
            st += ' ';
        }
        st.pop_back();
        return st;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string a = "the sky is blue";
    cout << Solution().reverseWords(a);
    return 0;
}