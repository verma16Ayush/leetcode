/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& a) 
    {
        int n = a.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(a[i][j], a[j][i]);
            }
        }

        for(vector<int>& i : a)
        {
            reverse(i.begin(), i.end());
        }
        
    }
};
// @lc code=end

