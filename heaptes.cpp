/** 
 *
 * @author - Ayush
 * @title - heaptes.cpp
 * @createdOn - 2021-06-07 07:23 Hrs
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

// struct cmp
// {
//     bool operator()(pair<int, int>& a, pair<int, int>& b)
//     {
//         return a.second > b.second;
//     }
// };

struct cmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        int d1 = a[0] * a[0] + a[1] * a[1];
        int d2 = b[0] * b[0] + b[1] * b[1];
        
        return d1 < d2;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO
    int n;
    cin >> n;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for(int i = 0; i < n; i++)
    {
        int k, l;
        cin >> k >> l;
        pq.push({k, l});
    }

    while(pq.size())
    {
        vector<int> k = pq.top();
        pq.pop();
        cout << k[0] << " " << k[1] << " " << k[0] * k[0] + k[1] * k[1] << nl;
    }
    cout << sizeof(bool) << endl;
    
    return 0;
}