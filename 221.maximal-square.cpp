/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++)
        {
            dp[i][0] = matrix[i][0] - '0';
        }
        for(int i = 0; i < matrix[0].size(); i++)
        {
            dp[0][i] = matrix[0][i] - '0';
        }

        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
        int ans = 0;
        for(vector<int>& i : dp)
        {
            ans = max(ans, *max_element(i.begin(), i.end()));
        }
        return ans * ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<char>> a(4, vector<char>(5));
    for(vector<char>& i : a)
    {
        for(char& j : i)
        {
            cin >> j;
        }
    }
    Solution sol;
    cout << sol.maximalSquare(a) << endl;
    return 0;
}