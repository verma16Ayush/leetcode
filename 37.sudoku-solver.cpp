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
    bool validate(const vector<vector<char>>& board, int i, int j, char c)
    {
        //row
        for(int col = 0; col < 9; col++) 
            if(board[i][col] == c) 
                return false;

        //column
        for(int row = 0; row < 9; row++) 
            if(board[row][j] == c) 
                return false;
                
        //subgrid
        int sr = i - i % 3;
        int sc = j - j % 3;
        for(int row = sr; row < sr + 3; row++)
            for(int col = sc; col < sc + 3; col++)
                if(board[row][col] == c) 
                    return false;
        
        //all fine
        return true;
    }

    bool dfs(vector<vector<char>>& board, int i)
    {
        if(i == 81) return true;
        if(board[i / 9][i % 9] != '.') return dfs(board, i + 1);
        for(char c = '1'; c <= '9'; c++)lee
        {
            if(validate(board, i / 9, i % 9, c))
            {
                board[i / 9][i % 9] = c;
                if(dfs(board, i + 1)) return true;
                else board[i / 9][i % 9] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
        return;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    sol.solveSudoku(board);
    return 0;
}
