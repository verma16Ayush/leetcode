/** 
 *
 * @author - Ayush
 * @title - longestIncereasingSubseq.cpp
 * @createdOn - 2021-03-12 18:02 Hrs
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


int Solve(vector<int>& a)
{
    vector<int> dp(a.size());
    for(int& i : dp) i = 1;
    for(int j = 1; j < a.size(); j++)
    {
        for(int i = 0; i < j; i++)
        {
            if(a[j] > a[i]) dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
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
        cout << Solve(a) << nl;
    }
    return 0;
}