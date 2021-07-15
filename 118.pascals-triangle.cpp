/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows, vector<int>());
        a[0] = vector<int>(1, 1);
        if(numRows >= 2) a[1] = vector<int>(2, 1);
        for(int i = 0; i < numRows; i++)
        {
            a[i] = vector<int>(i + 1, 0);
            a[i][0] = a[i][i] = 1;
            int k = 0;
            for(int j = 1; j < i; j++)
            {
                a[i][j] = a[i - 1][k] + a[i - 1][k + 1];
                k++;
            }
        }
        return a;
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
    vector<vector<int>> ans = sol.generate(1);
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}