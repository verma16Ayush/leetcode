/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) 
    {
        vector<int> ans;
        ans.reserve(a.size() * a[0].size());
        int i = 0;
        int k = 0;
        int cs = a[0].size();
        int rs = a.size();

        while(ans.size() != a.size() * a[0].size())
        {
            for(int l = 0 + k; l < cs - k; l++)
            {
                ans.push_back(a[k][l]);
            }

            if(ans.size() == a.size() * a[0].size()) break;
            for(int l = 0 + k + 1; l < rs - k; l++)
            {
                ans.push_back(a[l][cs - k - 1]);
            }

            if(ans.size() == a.size() * a[0].size()) break;
            for(int l = 0 + k + 1; l < cs - k; l++)
            {
                ans.push_back(a[rs - k - 1][cs - l - 1]);
            }
            if(ans.size() == a.size() * a[0].size()) break;

            k++;
            for(int l = 0 + k + 1; l < rs - k; l++)
            {
                ans.push_back(a[rs - k - 1][k - 1]);
            }
            if(ans.size() == a.size() * a[0].size()) break;
        }
        return ans;
    }
};
// @lc code=end

