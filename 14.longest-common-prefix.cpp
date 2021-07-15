/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        int i = 0;
        int j = 0;
        string temp = "";
        while(i < strs[0].length() && i < strs[1].length() && strs[0][i] == strs[1][j]) i++, j++;
        if(i == 0 || j == 0) return string();
        temp = strs[0].substr(0, i);
        for(int k = 2; k < strs.size(); k++)
        {
            i = 0, j = 0;
            while(i < temp.length() && j < strs[k].length() && strs[k][j] == temp[i]) i++, j++;
            temp = temp.substr(0, i);
        }
        return temp;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<string> str = {"flower","flow","flight"};
    cout << Solution().longestCommonPrefix(str);
    return 0;
}
