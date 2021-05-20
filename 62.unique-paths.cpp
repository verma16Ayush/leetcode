/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> a(m, vector<int> (n));
        for(int i = 0; i < m; i++) a[i][0] = 1;
        for(int i = 0; i < n; i++) a[0][i] = 1;

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                a[i][j] += a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[m - 1][n - 1];
    }
};
// @lc code=end

