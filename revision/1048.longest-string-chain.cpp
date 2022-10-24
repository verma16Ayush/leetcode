/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int dp[17][17];
    int dpp[1001];
    int LcsHelp(string& a, string& b, int n, int m)
    {
        if(n == 0 || m == 0)
            return dp[n][m] = 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(a[n - 1] == b[m - 1])
            return dp[n][m] = 1 + LcsHelp(a, b, n - 1, m - 1);
        else
            return dp[n][m] = max(LcsHelp(a, b, n - 1, m), LcsHelp(a, b, n, m - 1));
    }
    int LongestCommonSubseq(string text1, string text2) {
        memset(dp, -1, sizeof(int) * 17 * 17);
        return LcsHelp(text1, text2, text1.size(), text2.size());
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [&](const string& a, const string& b)->bool{
            return a.length() < b.length();
        });

        // memset(dpp, 0, sizeof(int) * 1001);
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(abs((int)(words[i].size()) - (int)(words[j].size())) == 1 && LongestCommonSubseq(words[i], words[j]) == max(words[i].size(), words[j].size()) - 1)
                {
                    dpp[j] = max(1 + dpp[i], dpp[j]);
                }
            }
        }
        return *max_element(&dpp[0], &dpp[words.size()]) + 1;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<string> a = {"abcd","dbqca"};
    // cout << Solution().LongestCommonSubseq(a[0], a[1]);
    cout << Solution().longestStrChain(a);
    return 0;
}