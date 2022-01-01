/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
typedef long long ll;
class Solution {
public:
    vector<ll> PrefixSum(vector<int>& a)
    {
        vector<ll> ps(a.size());
        if(a.size() == 1)
            return ps = {a[0]};
        else if(a.size() == 0)
            return {};

        reverse(a.begin(), a.end());
        ps[0] = a[0];
        for(int i = 1; i < a.size(); i++)
        {
            ps[i] = a[i];
            ps[i] += ps[i - 1];
        }
        reverse(ps.begin(), ps.end());
        return ps;
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<ll> ps = PrefixSum(shifts);
        for(int i = 0; i < s.size(); i++)
            s[i] = ((s[i] - 'a') + ps[i]) % 26 + 'a';
        return s;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string a = "abc";
    vector<int> as  = {3,5,9};
    cout << Solution().shiftingLetters(a, as);
    return 0;
}

