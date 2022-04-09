/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool ValidateBoard(const vector<vector<char>>& board, int r, int c, char val)
    {
        // validate row
        for(int i = 0; i < 9; i++)
            if(board[r][i] == val)
                return false;

        // validate col
        for(int i = 0; i < 9; i++)
            if(board[i][c] == val)
                return false;
        // validate sub
        int i_sub = r - r % 3;
        int j_sub = c - c % 3;
        for(int i = i_sub; i < i_sub + 3; i++)
            for(int j = j_sub; j < j_sub + 3; j++)
                if(board[i][j] == val)
                    return false;

        // all good
        return true;
    }

    bool DFS(vector<vector<char>>& board, int i)
    {
        if(i == 81)
            return true;
        int r = i / 9;
        int c = i % 9;

        if(board[r][c] != '.')
            return DFS(board, i + 1);
        
        for(char ch = '1'; ch <= '9'; ch++)
        {
            if(ValidateBoard(board, r, c, ch))
            {
                board[r][c] = ch;
                if(DFS(board, i + 1))
                    return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        DFS(board, 0);
    }
};
// @lc code=end

