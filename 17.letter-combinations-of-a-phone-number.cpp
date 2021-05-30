/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> a;

    vector<string> ans;
    void GetCom(string d, int i = 0, string res = "")
    {
        if(i == d.length())
        {
            ans.push_back(res);
            // res = "";
            return;
        }
        for(int j = 0; j < a[d[i] - '0'].length(); j++)
        {
            res.push_back(a[d[i] - '0'][j]);
            GetCom(d, i + 1, res);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty()) return {};
        a = vector<string>(10);
        ans = vector<string>();
        a[0] = "";
        a[1] = "";    
        a[2] = "abc";
        a[3] = "def";
        a[4] = "ghi";
        a[5] = "jkl";
        a[6] = "mno";
        a[7] = "pqrs";
        a[8] = "tuv";
        a[9] = "wxyz";
        GetCom(digits);
        return ans;
    }
};
// @lc code=end

// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     string di ="236";

//     Solution sol;
//     sol.letterCombinations(di);
//     for(string i : sol.ans) cout << i << " ";
//     cout << endl;
//     return 0;
// }
