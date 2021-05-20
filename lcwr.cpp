/** 
 *
 * @author - Ayush
 * @title - longest_substr_without_rep.cpp
 * @createdOn - 2021-04-28 00:30 Hrs
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
class Solution
{
private:
    int HasRep(unordered_map<char, int> mp, unordered_set<char>& keyset)
    {
        if(keyset.empty()) return 0;
        for(auto key : keyset)
        {
            if(mp[key] > 1) return 1;
        }
        return 0;
    }
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        unordered_set<char> keyset;
        keyset.insert(s[j++]);
        int mx = 0;
        while(j < s.length())
        {
            char c = s[j];
            while(keyset.find(c) != keyset.end())
            {
                keyset.erase(s[i++]);
            }
            keyset.insert(c);
            j++;
            mx = max((int)keyset.size(), mx);
        }
        return mx;
    }
};
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    string str;
    cin >> str;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(str) << nl;
    return 0;
}