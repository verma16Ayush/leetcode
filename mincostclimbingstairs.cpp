/** 
 *
 * @author - Ayush
 * @title - mincostclimbingstairs.cpp
 * @createdOn - 2021-02-25 13:23 Hrs
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

int dp[1001];

int Calc(vector<int>& cost, int n)
{
    if(n <= 2)
    {
        return dp[n] = cost[n - 1];
    }
    return dp[n] = cost[n - 1] + min(Calc(cost, n - 1), Calc(cost, n - 2));
}

int minCostClimbingStairs(vector<int>& cost) 
{
    memset(dp, -1, sizeof(dp));
    Calc(cost, cost.size());
    return min(dp[cost.size()], dp[cost.size() - 1]);
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& i : a) cin >> i;
        cout << minCostClimbingStairs(a) << nl;
    }
    return 0;
}