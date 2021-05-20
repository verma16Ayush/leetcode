/** 
 *
 * @author - Ayush
 * @title - valid_paren.cpp
 * @createdOn - 2021-04-29 16:04 Hrs
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
class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char, pair<string, char>> chk;
        chk['['] = {"open", '['};
        chk[']'] = {"close", '['};
        chk[')'] = {"close", '('};
        chk['('] = {"open", '('};
        chk['}'] = {"close", '{'};
        chk['{'] = {"open", '{'};
        stack<char> st;

        for(auto i : s)
        {
            if(chk[i].first == "open")
            {
                st.push(i);
            }
            else if(chk[i].first == "close")
            {
                if(st.empty()) return 0;
                else if(chk[i].second == st.top()) st.pop();
                else return 0;
            }
        }
        return st.empty();
    }
};
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s) << nl;
    return 0;
}