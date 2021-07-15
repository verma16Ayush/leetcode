/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
typedef long long ll;
constexpr ll mod = 1e9 + 7;
class Solution {
public:
    unordered_map<char, vector<char>> mp;
    int countVowelPermutation(int n) {
        int dp[n + 1][5];
        for(int i = 0; i < 5; i++) dp[1][i] = 1;

        for(int i = 2; i <= n; i++)
        {
            dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod; 
        }
        long long ans = 0;
        for(int i = 0; i < 5; i++)
        {
            ans = (ans + dp[n][i]) % mod;
        }
        return ans;
    }
};
// @lc code=end

