/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) 
    {
        vector<int> ps(a.size() + 1);
        ps[0] = 0;
        for(int i = 0; i < a.size(); i++)
        {
            ps[i + 1] = a[i];
            ps[i + 1] += ps[i];
            ps[i + 1] = ((ps[i + 1] % k) + k) % k;
        }

        map<int, int> mod;
        for(int i = 1; i < ps.size(); i++)
        {
            mod[ps[i]]++;
        }

        int ans = 0;
        for(auto it : mod)
        {
            ans += (it.second * (it.second - 1)) / 2;
        }
        return ans + mod[0];
    } 
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {4,5,0,-2,-3,1};
    Solution sol;
    cout << sol.subarraysDivByK(a, 5) << endl;
    return 0;
}