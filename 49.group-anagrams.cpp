/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for(auto str : strs)
        {
            string t = str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
// @lc code=end

