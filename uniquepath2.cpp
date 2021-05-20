/** 
 *
 * @author - Ayush
 * @title - uniquepath2.cpp
 * @createdOn - 2021-03-20 11:53 Hrs
 * 
 **/
#include <iostream>
#include <bits/stdc++.h>
#define nl '\n'
#define int ll
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
typedef long long ll;
using namespace std;

ll PowModulo(ll a, ll b)
{
    ll res = 1;
    a = a % MOD;
    if(b == 0) return 1;
    if(a == 0) return 0;
    while(b)
    {
        if(b & 1) res = (res * a) % MOD;
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return res;
}

vector<int> PrefixSum(const vector<int>& a)
{
    vector<int> ps(a.size() + 1);
    ps[0] = 0;
    for(int i = 1; i <= a.size(); i++)
    {
        ps[i] = a[i - 1];
        ps[i] += ps[i - 1];
    }
    return ps;
}

class Solution {
public:
    int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < obstacleGrid.size(); i++) 
        {
            for(int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i < obstacleGrid.size(); i++)
        {
            if(dp[i][0] == 0) continue;
            dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i < obstacleGrid[0].size(); i++)
        {
            if(dp[0][i] == 0) continue;
            dp[0][i] = dp[0][i - 1];
        }

        for(int i = 1; i < obstacleGrid.size(); i++)
        {
            for(int j = 1; j < obstacleGrid[0].size(); j++)
            {
                if(dp[i][j] == 0) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int tc = 1;
    while(tc--)
    {
        vector<vector<int>> a = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };

        Solution* sol = new Solution();
        cout << sol->uniquePathsWithObstacles(a) << nl;
    }
    return 0;
}