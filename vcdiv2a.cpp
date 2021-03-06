/** 
 *
 * @author - Ayush
 * @title - vcdiv2a.cpp
 * @createdOn - 2021-03-17 13:20 Hrs
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
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int a[26] = {0};
    string str;
    cin >> str;
    if(str.length() < 26) 
    {
        cout << -1 << nl;
        return 0;
    }
    else
    {
        int flag = 0;
        int di = -1;
        string req = "";
        for(int i = 0; i < str.length(); i++)
        {
            memset(a, 0, sizeof(a));
            int c0 = 0;
            int cq = 0;
            for(int j = 0; i + j < str.length() && j < 26; j++)
            {
                if(str[i + j] == '?')
                {
                    cq++;
                }
                else
                {
                    a[str[i + j] - 'A']++;
                    if(a[str[i + j] - 'A'] > 1)
                    {
                        break;
                    }
                }
                if(j == 25)
                {
                    di = i;
                }
            }
            if(di != -1)
            {
                req = "";
                for(int i = 0; i < 26; i++)
                {
                    if(a[i] == 0)
                    {
                        c0++;
                        req += 'A' + i;
                    }
                }
                if(c0 == cq) 
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            int k = 0;
            for(int i = 0; i < 26; i++)
            {
                if(str[i + di] == '?')
                {
                    cout << req[k++];
                    continue;
                }
                cout << str[i + di];
            }
        }
        else cout << -1;
        cout << nl;
    }
    return 0;
}