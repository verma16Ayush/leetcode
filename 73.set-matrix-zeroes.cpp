/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) 
    {
        vector<int> rm, cm;
        rm = vector<int>(a.size());
        cm = vector<int>(a[0].size());
        memset(&rm[0], -1, rm.size() * sizeof(int));
        memset(&cm[0], -1, cm.size() * sizeof(int));

        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 0; j < a[0].size(); j++)
            {
                if(a[i][j] == 0) rm[i] = 0, cm[j] = 0;
            }
        }

        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 0; j < a[0].size(); j++)
            {
                if(rm[i] == 0 || cm[j] == 0) a[i][j] = 0;
            }
        }
    }
};
// @lc code=end

