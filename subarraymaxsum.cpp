/** 
 *
 * @author - Ayush
 * @title - subarraymaxsum.cpp
 * @createdOn - 2021-04-15 23:03 Hrs
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
    int dp[3 * (int)1e4 + 1];

    int GetAns(const vector<int>& nums, int n)
    {
        if(dp[n - 1] != -1) return dp[n - 1];
        if(n == 1) return dp[n - 1] = nums[n - 1];
        return dp[n - 1] = max(nums[n - 1], nums[n - 1] + GetAns(nums, n - 1));
    }

    int maxSubArray(vector<int>& nums) 
    {
        memset(dp, -1, sizeof(dp));
        GetAns(nums, nums.size());
        return *max_element(dp, dp + nums.size());
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    Solution* sol = new Solution();
    cout << sol->maxSubArray(a);

    return 0;
}