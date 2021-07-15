/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size() * mat[0].size() != r * c) return mat;
        int k = 0;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                ans[k / c][k % c] = mat[i][j];
                k++;
            }
        }
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {
                            {1, 2},
                            {3, 4},
                        };
    Solution sol;
    auto ans = sol.matrixReshape(a, 1, 4);
    return 0;
}