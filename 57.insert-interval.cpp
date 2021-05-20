/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) 
    {
        vector<vector<int>> res;
        int i = 0;
        while(i < a.size() && a[i][1] < b[0])
        {
            res.push_back(a[i++]);
        }
        while(i < a.size() && a[i][0] <= b[1])
        {
            b[0] = min(b[0], a[i][0]);
            b[1] = max(b[1], a[i][1]);
            i++;
        }
        res.push_back(b);
        while(i < a.size())
        {
            res.push_back(a[i++]);
        }
        return res;
    }
};
// @lc code=end

