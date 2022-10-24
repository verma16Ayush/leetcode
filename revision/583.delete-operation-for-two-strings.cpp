/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[501][501];
    int LongestCommonSubseq(string s1, int n, string s2, int m)
    {
        if(dp[n][m] != -1)
            return dp[n][m];
        if(n == 0 || m == 0)
            return dp[n][m] = 0;
        if(s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + LongestCommonSubseq(s1, n - 1, s2, m - 1);
        return dp[n][m] = max(LongestCommonSubseq(s1, n - 1, s2, m), LongestCommonSubseq(s1, n, s2, m - 1));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(int) * 501 * 501);
        int lcs = LongestCommonSubseq(word1, word1.size(), word2, word2.size());
        return word1.size() + word2.size() - 2 * lcs;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout << Solution().minDistance("ayush", "verma");
    return 0;
}