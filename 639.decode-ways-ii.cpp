/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
constexpr int MOD = (int)1e9 + 7;
class Solution {
public:
    int dp[101];
    vector<string> q;

    int CounWays(string s, int n)
    {
        if(dp[n] != -1) return dp[n];
        if(n < 0) return 0;
        if(n == 0) return dp[n] = 1;
        if(n == 1)
        {
            if(s[n - 1] != '0') return dp[n] = 1;
            else return dp[n] = 0;
        }
        char dl = s[n - 1];
        char dsl = s[n - 2];
        
        int ans = 0;
        if(dl == '0' && (dsl == '1' || dsl == '2')) ans += CounWays(s, n - 2);
        if(dsl == '1' && dl >= '1' && dl <= '9') ans += CounWays(s, n - 2);
        if(dsl == '2' && dl >= '1' && dl <= '6') ans += CounWays(s, n - 2);
        if(dl != '0') ans += CounWays(s, n - 1);
        return dp[n] = ans;
    }

    void dfs(string s, int i, string temp)
    {
        if(i == s.length())
        {
            q.push_back(temp);
            return;
        }
        if(s[i] == '*')
        {
            for(char c = '1'; c <= '9'; c++)
            {
                temp.push_back(c);
                dfs(s, i + 1, temp);
                temp.pop_back();
            }
        }
        else
        {
            temp.push_back(s[i]);
            dfs(s, i + 1, temp);
        }
    }

    int numDecodings(string s)
    {
        dfs(s, 0, string());
        int ans = 0;
        for(string i : q)
        {
            memset(dp, -1, sizeof(dp));
            ans += (CounWays(i, i.length())) % MOD;
        }
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "1*";
    Solution sol;
    cout << sol.numDecodings(s);
    return 0;
}