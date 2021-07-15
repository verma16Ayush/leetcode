/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int help(vector<int>& a, vector<int>& b, int n, int m)
    {
        if(dp[n][m] != -1) return dp[n][m];
        if(n == 0 || m == 0) return dp[n][m] = 0;
        else if(a[n - 1] == b[m - 1]) dp[n][m] = 1 + help(a, b, n - 1, m - 1);
        else dp[n][m] = 0;
        help(a, b, n - 1, m);
        help(a, b, n, m - 1);
        return dp[n][m];

        // int res = 0;
        // for(int i = 0; i <= n; i++) dp[i][0] = 0;
        // for(int i = 0; i <= m; i++) dp[0][i] = 0;
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++)
        //     {
        //         if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
        //         else dp[i][j] = 0;

        //         res = max(res, dp[i][j]);
        //     }
        // }
        // return res;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        help(nums1, nums2, nums1.size(), nums2.size());
        int mx = 0;
        for(int i = 0; i <= nums1.size(); i++) for(int j = 0; j <= nums2.size(); j++) mx = max(mx, dp[i][j]);
        return mx;
        // return *max_element(&dp[0][0], &dp[1000][1000]);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {0,0,0,0,0,0,1,0,0,0};
    vector<int> b = {0,0,0,0,0,0,0,1,0,0};
    Solution sol;
    cout << sol.findLength(a, b);
    return 0;
}