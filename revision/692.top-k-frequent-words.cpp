/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string wrd : words)
            mp[wrd]++;
        vector<vector<string> > freq_mp(500);
        for(auto p : mp)
        {
            freq_mp[p.second].push_back(p.first);
        }

        vector<string> ans;
        int i = freq_mp.size() - 1;
        while(i >= 0 && ans.size() != k)
        {
            if(freq_mp[i].size())
            {
                sort(freq_mp[i].begin(), freq_mp[i].end());
                for(int j = 0; j < freq_mp[i].size() && ans.size() != k; j++)
                {
                    ans.push_back(freq_mp[i][j]);
                }
            }
            i--;
        }
        return ans;
    }
};
// @lc code=end

