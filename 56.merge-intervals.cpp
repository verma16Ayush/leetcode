/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


int compare(vector<int>& a, vector<int>& b)
{
    if(a[0] < b[0]) return true;
    else return false;
}
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int i = 1;
        while(i < intervals.size())
        {
            if(intervals[i][0] <= res.back()[1]) 
            {
                if(intervals[i][1] > res.back()[1]) res.back()[1] = intervals[i][1];
            }
            else res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
// @lc code=end

