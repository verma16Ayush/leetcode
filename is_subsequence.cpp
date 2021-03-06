/** 
 *
 * @author - Ayush
 * @title - is_subsequence.cpp
 * @createdOn - 2021-02-25 19:45 Hrs
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

bool isSubsequence(string s, string t) 
{
    stack<char> s1;
    if((s.size() == 0 && t.size())) return 1;
    if(s.size() && t.size() == 0) return 0;
    for(int i = 0; i < s.size(); i++)
    {
        s1.push(s[i]);
    }        
    for(int i = t.size() - 1; i >= 0; i--)
    {
        if(s1.top() == t[i]) s1.pop();
        if(s1.size() == 0) break;
    }
    return s1.size()== 0;
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
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        cout << isSubsequence(str1, str2);
    }
    return 0;
}