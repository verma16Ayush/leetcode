/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int IsAna(vector<int>& mp1, vector<int>& mp2)
    {
        for(int i = 0; i < 26; i++)
        {
            if(mp1[i] != mp2[i]) return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) 
    {
        if(p.size() > s.size()) return {};
        vector<int> mp(26);
        vector<int> ms(26);
        for(int i = 0; i < p.size(); i++) 
        {
            mp[p[i] - 'a']++;
            ms[s[i] - 'a']++;
        }

        vector<int> ans;
        if(IsAna(mp, ms)) ans.push_back(0);
        for(int i = 0, j = p.size() - 1; j + 1 < s.size(); i++, j++)
        {
            ms[s[i] - 'a']--;
            ms[s[j + 1] - 'a']++;
            if(IsAna(ms, mp)) ans.push_back(i + 1);
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
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> a = sol.findAnagrams(s, p);
    return 0;
}