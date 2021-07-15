/** 
 *
 * @author - Ayush
 * @title - hello.cpp
 * @createdOn - 2021-07-08 11:44 Hrs
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

vector<int> dp;
int solve(int n, int a, int b, int c)
{
    if(n < 0) return INT32_MIN;
    if(dp[n] != -1) return dp[n];
    if(n == 0) return dp[n] = 0;
    return dp[n] = max({solve(n - a, a, b, c), solve(n - b, a, b, c), solve(n - c, a, b, c)}) + 1;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp = vector<int>(n + 1);
    memset(&dp[0], -1, (n + 1) * sizeof(int));
    cout << solve(n, a, b, c);
    return 0;
}