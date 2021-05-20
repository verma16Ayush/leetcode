/** 
 *
 * @author - Ayush
 * @title - lightson.cpp
 * @createdOn - 2021-03-17 12:30 Hrs
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
    bool a[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
        };
    int b[3][3] = {0};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> b[i][j];
            if(b[i][j] % 2)
            {
                a[i][j] = !a[i][j];
                if(i - 1 >= 0)
                {
                    a[i - 1][j] = !a[i - 1][j];
                }
                if(j - 1 >= 0)
                {
                    a[i][j - 1] = !a[i][j - 1];
                }
                if(i + 1 <= 2) a[i + 1][j] = !a[i + 1][j];
                if(j + 1 <= 2) a[i][j + 1] = !a[i][j + 1];
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << a[i][j];
        }
        cout << nl;
    }
    
    return 0;
}