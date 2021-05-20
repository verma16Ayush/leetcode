/** 
 *
 * @author - Ayush
 * @title - word_break.cpp
 * @createdOn - 2021-03-14 13:32 Hrs
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

int dp[301];
unordered_set<string> mp;

int Count(string s, int st)
{
    if(dp[st] != -1) return dp[st];
    if(s.length() == st) return dp[st] = 1;
    for(int i = 1; st + i <= s.length(); i++)
    {
        if(mp.find(s.substr(st, i)) != mp.end() && Count(s, st + i)) return dp[st] = 1;
    }
    return dp[st] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) 
{
    memset(dp, -1, sizeof(dp));
    for(string s : wordDict) mp.insert(s);
    return Count(s, 0);
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
        string s;
        cin >> s;
        int n;
        cin >> n;
        vector<string> dic(n);

        for(string& i : dic) cin >> i;
        cout << wordBreak(s, dic) << nl;
        getchar();
    }
    return 0;
}