/** 
 *
 * @author - Ayush
 * @title - countpalindromicsubstr.cpp
 * @createdOn - 2021-02-27 12:59 Hrs
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

int dp[1001][1001];


bool IsPalin(string& str, int s, int e)
{
    int i = s, j = e;
    while(i <= j) if(str[i++] != str[j--]) return false;
    return true;
}


int CountPalinSubstr(string a, int s, int e)
{
    if(dp[s][e] != -1) return dp[s][e];
    if(s > e) return dp[s][e] = 0;
    int ans = 0;
    if(IsPalin(a, s, e)) ans += 1;
    ans += CountPalinSubstr(a, s + 1, e);
    ans += CountPalinSubstr(a, s, e - 1);
    ans -= CountPalinSubstr(a, s + 1, e - 1);
    return dp[s][e] = ans;
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
        string a;
        cin >> a;
        memset(dp, -1, sizeof(dp));
        cout << CountPalinSubstr(a, 0, a.length() - 1) << nl;
    }
    return 0;
}