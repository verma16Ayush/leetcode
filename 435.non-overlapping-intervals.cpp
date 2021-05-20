/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

bool operator<(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) 
    {
        if(a.size() <= 1) return 0;
        sort(a.begin(), a.end());
        int cnt = 0;
        int l = a[0][0];
        int r = a[0][1];
        int i = 1;

        while(i < a.size())
        {
            if(r > a[i][0])
            {
                if(r > a[i][1])
                {
                    l = a[i][0];
                    r = a[i][1];
                    cnt++;
                }
                else cnt++;
            }
            else
            {
                l = a[i][0];
                r = a[i][1];
            }
            i++;
        }
        return cnt;
    }
};
// @lc code=end

