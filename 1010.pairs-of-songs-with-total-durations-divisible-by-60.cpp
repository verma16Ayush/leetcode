/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mp(60);
        for(int i : time)
            mp[i % 60]++;
        int c = 0;
        for(int i = 1; i < 60; i++)
        {
            int t1 = i;
            int t2 = 60 - i;

            if(t1 == t2)
                c += mp[t1] * (mp[t2] - 1);
            
            else
                c += mp[t1] * mp[t2];
        }
        c /= 2;
        c += (mp[0] * (mp[0] - 1)) / 2;
        return c;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {60, 120, 180};
    Solution sol;
    cout << sol.numPairsDivisibleBy60(a);
    return 0;
}