/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> PrefixSum(vector<int>& a)
    {
        vector<int> ps(a.size());
        ps[0] = a[0];
        for(int i = 1; i < a.size(); i++)
        {
            ps[i] = a[i];
            ps[i] += ps[i - 1];
        }
        return ps;
    }
    int SumHelp(vector<int>& ps, int st, int en, int numSplits)
    {
        if(numSplits + 1 > en - st + 1)
            return -1;
        for(int i = st; i <= en; i++)
        {
            return min(max())
        }
    }
    int splitArray(vector<int>& nums, int m) {
        
    }
};
// @lc code=end

