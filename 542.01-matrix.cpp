/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    vector<pair<int, int>> dir;
    bool isvalid(vector<vector<int>>& mat, int i, int j)
    {
        if(i >= mat.size() || j >= mat[0].size() || i < 0 || j < 0) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        dp = vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), INT32_MAX));
        dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for(int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if(mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = INT16_MAX;
            } // for(j)
        } // for(i)
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            for(auto d : dir)
            {
                if(isvalid(mat, front.first + d.first, front.second + d.second) && mat[front.first + d.first][front.second + d.second] > mat[front.first][front.second] + 1)
                {
                    q.push({front.first + d.first, front.second + d.second});
                    mat[front.first + d.first][front.second + d.second] = 1 + mat[front.first][front.second];
                }
            }
        } // while(q.size())
        return mat;
    } // updateMatrix
}; // Solution
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // vector<vector<int>> a = {
    //     {1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
    //     {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    //     {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
    //     {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    //     {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
    //     {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
    //     {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
    //     {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    //     {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    //     {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}
    // };
    vector<vector<int>> a = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    auto ans = Solution().updateMatrix(a);
    return 0;
}
