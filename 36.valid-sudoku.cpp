/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validateRow(vector<vector<char>>& board, int r)
    {
        unordered_set<char> row;
        for(int i = 0; i < 9; i++)
        {
            if(board[r][i] == '.') continue;
            if(row.find(board[r][i]) != row.end()) return false;
            row.insert(board[r][i]);
        }
        return true;
    }

    bool validateColumn(vector<vector<char>>& board, int c)
    {
        unordered_set<char> col;
        for(int i = 0; i < 9; i++)
        {
            if(board[i][c] == '.') continue;
            if(col.find(board[i][c]) != col.end()) return false;
            col.insert(board[i][c]);
        }
        return true;
    }

    bool validateSubgrid(vector<vector<char>> & board, int r, int c)
    {
        unordered_set<char> subgrid;
        for(int i = r; i < r + 3; i++)
        {
            for(int j = c; j < c + 3; j++)
            {
                if(board[i][j] == '.') continue;
                if(subgrid.find(board[i][j]) != subgrid.end()) return false;
                subgrid.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) 
            if(!(validateColumn(board, i) && validateRow(board, i))) 
                return false;

        
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
                if(!validateSubgrid(board, i, j)) return false;
        
        return true;
    }
};
// @lc code=end

