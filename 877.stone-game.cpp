/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[500][500];
    bool help(vector<int>& a, int s, int e, int al = 0, int le = 0)
    {
        if(dp[s][e] != -1) return dp[s][e];
        if(s + 1 == e) return dp[s][e] = (al + a[s] > le + a[e] || al + a[e] > le + a[s]);
        if((e - s + 1) % 2 == 0)
            return dp[s][e] = (help(a, s + 1, e, al + a[s], le) || help(a, s, e - 1, al + a[e], le));
        return dp[s][e] = (help(a, s + 1, e, al, le + a[s]) || help(a, s, e - 1, al, le + a[e]));
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return help(piles, 0, piles.size() - 1, 0, 0);
    }
};
// @lc code=end

