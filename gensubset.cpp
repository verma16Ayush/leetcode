/** 
 *
 * @author - Ayush
 * @title - gensubset.cpp
 * @createdOn - 2021-03-19 22:42 Hrs
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

vector<vector<int>> subs;
vector<int> set;
void GenSubs(vector<int>& n, vector<int> set, int sz)
{
    if(sz == 0)
    {
        subs.push_back(set);
        set.clear();
        return;
    }
    set.push_back(n[sz - 1]);
    GenSubs(n , set, sz - 1);
    set.pop_back();
    GenSubs(n, set, sz - 1);

}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    GenSubs();
    return subs;
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
        
    }
    return 0;
}