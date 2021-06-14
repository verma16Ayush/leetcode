/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<pair<int, int>> range(26, make_pair(-1, -1));
        for(int i = 0; i < s.length(); i++)
        {
            if(range[s[i] - 'a'].first == -1) range[s[i] - 'a'].first = i;
            range[s[i] - 'a'].second = i;
        }
        vector<pair<int, int>> fin_ranges;
        fin_ranges.push_back(range[s[0] - 'a']);
        for(int i = 1; i < (int)s.length(); i++)
        {
            if(range[s[i] - 'a'].first < fin_ranges.back().second && range[s[i] - 'a'].second > fin_ranges.back().second) fin_ranges.back().second = range[s[i] - 'a'].second;
            else if(range[s[i] - 'a'].first > fin_ranges.back().second) fin_ranges.push_back(range[s[i] - 'a']);
        }
        
        vector<int> ans;
        for(auto i : fin_ranges)
        {
            ans.push_back(i.second - i.first + 1);
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
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    sol.partitionLabels(s);
    return 0;
}