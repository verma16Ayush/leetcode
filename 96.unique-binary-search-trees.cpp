/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[20][20];
    
    int CalcTable(int low, int high)
    {
        if(high <= low) return 1;
        if(dp[low][high] != -1) return dp[low][high];
        if(high - low == 1) return dp[low][high] = 2;
        int ans = 0;
        for(int i = low; i <= high; i++)
        {
            ans += CalcTable(low, i - 1) * CalcTable(i + 1, high);
        }
        return dp[low][high] = ans;
    }

    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return CalcTable(1, n);
    }
};
// @lc code=end


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    cout << sol.numTrees(8) << endl;
    return 0;
}