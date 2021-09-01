/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int SubseqCount(string& s, string& t, int n, int m)
    {
        if(dp[n][m] != -1) return dp[n][m];
        if(m == 0) 
            return dp[n][m] = 1;
        if(n == 0) 
            return dp[n][m] = 0;
        if(s[n - 1] == t[m - 1]) 
            dp[n][m] = SubseqCount(s, t, n - 1, m - 1) + SubseqCount(s, t, n - 1, m);
        else 
            dp[n][m] = SubseqCount(s, t, n - 1, m);
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return SubseqCount(s, t, s.size(), t.size());
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "babgbag";
    string t = "bag";
    cout << Solution().numDistinct(s, t);
    return 0;
}
