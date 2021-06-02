/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
// #define int ll
typedef long long ll;
using namespace std;

class Solution {
public:
    ll dp[(ll)1e4 + 1][13];
    ll Fun(vector<int>& coins, ll amount, int m)
    {
        if(dp[amount][m] != -1) return dp[amount][m];
        if(amount == 0) return dp[amount][m] = 0;
        if(m == 0) return dp[amount][m] = INT32_MAX;
        if(coins[m - 1] <= amount) return dp[amount][m] = min({1 + Fun(coins, amount - coins[m - 1], m), Fun(coins, amount, m - 1)});
        else return dp[amount][m] = Fun(coins, amount, m - 1);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        ll k = Fun(coins, amount, coins.size());
        return k >= INT32_MAX || k < 0 ? -1 : k;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {2};
    Solution sol;
    cout << sol.coinChange(a, 3) << endl;
    return 0;
}
