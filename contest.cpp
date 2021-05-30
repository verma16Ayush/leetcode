/** 
 *
 * @author - Ayush
 * @title - contest.cpp
 * @createdOn - 2021-05-29 20:06 Hrs
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

bool cmp(int a, int b)
{
    int i = 31;
    int j = 31;
    int imx, jmx;
    for(i; i >= 0; i--)
    {
        if((1 << i) & a) 
        {
            imx = i;
            break;
        }
    }
    for(int j; j >= 0; j--)
    {
        if((1 << j) & b)
        {
            jmx = j;
            break;
        }
    }

    return imx < jmx;
}
class Solution {
public:
    string maxValue(string n, int x) 
    {
        string s = "";
        if(n[0] == '-')
        {
            s.push_back('-');
            int i = 1;
            while(i < n.length() && n[i] - '0' <= x)
            {
                s.push_back(n[i]);
                i++;
            }
            s.push_back('0' + x);
            while(i < n.length()) s += n[i++];
        }
        else 
        {
            // int i = 0;

            // while(i < n.length() && n[i] - '0' > x)
            // {
            //     s.push_back(n[i]);
            //     i++;
            // }
            // s.push_back('0' + x);
            // while(i < n.length()) s += n[i++];
            int i = n.length() - 1;
            while(i >= 0 && n[i] - '0' > x)
        }
        return s;
    }
};
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    cout << sol.maxValue("-132", 3) << endl;
    cout << sol.maxValue("-13", 2) << endl;
    cout << sol.maxValue("73", 2) << endl;
    cout << sol.maxValue("73", 6) << endl;
    return 0;
}