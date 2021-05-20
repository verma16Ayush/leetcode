/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct cp
{
    int c0;
    int c1;
    cp()
    {
        c0 = 0;
        c1 = 0;
    }
};
class Solution {
public:
    cp Count(string str)
    {
        cp ans;
        for(char c : str)
        {
            if(c == '0') ans.c0++;
            if(c == '1') ans.c1++;
        }
        return ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        cp dp[]
    }
};
// @lc code=end

