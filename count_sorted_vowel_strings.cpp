/** 
 *
 * @author - Ayush
 * @title - count_sorted_vowel_strings.cpp
 * @createdOn - 2021-02-26 14:27 Hrs
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
int dp[6][51];
int Count(vector<char> a, int j, int n, int cursize)
{
    if(dp[j][cursize] != -1) return dp[j][cursize];
    if(cursize == n) return 1;
    int ans = 0;
    for(int i = j; i <= 5; i++)
    {
        ans += Count(a, i, n, cursize + 1);
    }
    return dp[j][cursize] = ans;
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
        vector<char> a = {'a', 'e', 'i', 'o', 'u'};
        cout << Count(a, 1, n, 0) << nl;
        // cout << helper(a, 1, n, 0) << nl;
        // cout << countVowelStrings(n) << nl;
    }
    return 0;
}