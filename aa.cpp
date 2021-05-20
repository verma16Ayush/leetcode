/** 
 *
 * @author - Ayush
 * @title - aa.cpp
 * @createdOn - 2021-03-17 17:07 Hrs
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

int Sum(vector<int>& a)
{
    int sum = 0;
    for(int& i : a)
    {
        sum += i;
    }
    return sum;
}

int CheckMp(map<int, int>& a, map<int, int>& b)
{
    map<int, int>::iterator i = a.begin();
    map<int, int>::iterator j = b.begin();
    while(i != a.end() && j != b.end())
    {
        if(i->first == j->first && i->second == j->second)
        {
            i++;
            j++;
        }
        else return false;
    }
    return true;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    vector<int> b(n);
    for(int& i : b) cin >> i;

    map<int, int> mpa;
    map<int, int> mpb;

    for(int i : b)
    {
        mpb[i]++;
        mpa[i] = 0;
    }
    
    for(int i : a)
    {
        mpa[i]++;
    }

    if(CheckMp(mpa, mpb))
    {
        cout << 0 << nl;
        return 0;
    }
    int k = 0;
    pair<int, int> sta;
    pair<int, int> stb;
    for(auto& i : mpa)
    {
        for(auto& j : mpb)
        {
            if(i.second == j.second)
            {
                if(abs(i.first - j.first) > k)
                {
                    sta = i;
                    stb = j;
                    k = abs(i.first - j.first);
                }
            }
        }
    }

    if(k == 0)
    {
        cout << k << nl;
        return 0;
    }
    if(sta.first < sta.second)
    {
        cout << k << nl;
    }
    else
    {
        cout << m - k << nl;
    }
    return 0;
}