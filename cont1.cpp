/** 
 *
 * @author - Ayush
 * @title - cont1.cpp
 * @createdOn - 2021-09-28 20:05 Hrs
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

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        for(char c : s) mp[c]++;

        if(mp['A'] == mp['B'] && mp['C'] == 0)
            cout << "YES" << nl;
        else if(mp['B'] == mp['C'] && mp['A'] == 0)
            cout << "YES" << nl;
        else if(mp['B'] == mp['A'] + mp['C'])
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
            
    }
    return 0;
}