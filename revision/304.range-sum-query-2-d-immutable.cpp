/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> pstd;
    NumMatrix(vector<vector<int>>& matrix) {
        pstd = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++)
            pstd[i][0] = matrix[i][0];

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                pstd[i][j] = matrix[i][j];
                pstd[i][j] += pstd[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
        {
            sum += col1 - 1 < 0 ? pstd[i][col2] : pstd[i][col2] - pstd[i][col1 - 1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix numMatrix = *new NumMatrix(a);
    numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
    numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
    numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
    return 0;
}
