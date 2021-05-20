/** 
 *
 * @author - Ayush
 * @title - divisorgame.cpp
 * @createdOn - 2021-02-25 11:45 Hrs
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

vector<int> Factors(int a)
{
    vector<int> f;
    for(int i = 1; i * i < a; i++)
    {
        if(a % i == 0)
        {
            f.push_back(i);
            f.push_back(a / i);
        }
    }
    sort(f.begin(), f.end());
    return f;
}

int dp[100];

int Check(int n)
{
    if(dp[n] != -1) return dp[n];
    if(n < 2) return dp[n] = 0;
    for(int div = 1; div * div < n; div++)
    {
        if(n % div == 0)
        {
            if(Check(n - div) == 0) 
            {
                return dp[n] = 1;
                break;
            }
            if(Check(n - n / div) == 0 && div != 1)
            {
                return dp[n] = 1;
                break;
            }
        }
    }
    return dp[n] = 0;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << Check(n) << nl;
    return 0;
}