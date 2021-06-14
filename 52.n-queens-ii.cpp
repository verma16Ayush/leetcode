/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;
    bool IsValidConf(vector<string> board, int r, int c)
    {
        int n = board.size();

        // check column
        for(int i = 0; i < n; i++)
            if(board[i][c] == 'Q') return 0;

        //principal diagonal direction
        for(int i = r, j = c; i < n && j < n; i++, j++)
            if(board[i][j] == 'Q') return 0;
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if(board[i][j] == 'Q') return 0;
        
        // the other diagonal
        for(int i = r, j = c; i < n && j >= 0; i++, j--)
            if(board[i][j] == 'Q') return 0;
        for(int i = r, j = c; i >= 0 && j < n; i--, j++)
            if(board[i][j] == 'Q') return 0;
        
        // none of the conditioons fail
        return 1;
    }
    void dfs(vector<string> board, int r)
    {
        if(r == board.size()) 
        {
            ans++;
            return;
        }
        for(int i = 0; i < board.size(); i++)
        {
            if(IsValidConf(board, r, i))
            {
                board[r][i] = 'Q';
                dfs(board, r + 1);
                board[r][i] = '.';
            }
        }
    }
    int totalNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return ans;
    }
    
};
// @lc code=end

