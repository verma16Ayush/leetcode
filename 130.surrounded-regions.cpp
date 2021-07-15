/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<pair<int, int>> dir;
    int dp[200][200];
    bool touchesBorder(vector<vector<char>>& a, int i, int j)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 || i == a.size() - 1 || j == 0 || j == a[0].size() - 1) return dp[i][j] = 1;
        a[i][j] = '#';
        bool b = false;
        for(auto d : dir)
        {
            if( i + d.first >= 0 &&
                i + d.first < a.size() &&
                j + d.second >= 0 &&
                j + d.second < a[0].size() &&
                a[i + d.first][j + d.second] == 'O')
            {
                b = b || touchesBorder(a, i + d.first, j + d.second);
                if(b) break;
            }
        }
        a[i][j] = 'O';
        return dp[i][j] = b;
    }

    void flip(vector<vector<char>>& a, int i, int j)
    {
        a[i][j] = 'X';
        for(auto d : dir)
        {
            if( i + d.first >= 0 &&
                i + d.first < a.size() &&
                j + d.second >= 0 &&
                j + d.second < a[0].size() &&
                a[i + d.first][j + d.second] == 'O') flip(a, i + d.first, j + d.second);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        memset(dp, -1, sizeof(dp));
        dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dp[i][j] == -1 && board[i][j] == 'O' &&!touchesBorder(board,i, j))
                    flip(board, i, j);
            }
        }
    }  
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<char>> board;
    Solution sol;
    sol.solve(board);
    return 0;
}