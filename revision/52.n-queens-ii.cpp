/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> sols;
    vector<string> tempgrid;
    bool IsValid(vector<string>& grid, int r, int c)
    {
        int n = grid.size();
        for(int i = 0; i < r; i++)
            if(grid[i][c] == 'Q')
                return false;

        // diagonally upwards
        int i = r, j = c;
        while(i >= 0 && j >= 0)
        {
            if(grid[i][j] == 'Q')
                return false;
            i -= 1;
            j -= 1;
        }

        i = r, j = c;
        while(i >= 0 && j < n)
        {
            if(grid[i][j] == 'Q')
                return false;
            i -= 1;
            j += 1;
        }

        i = r, j = c;
        while(i < n && j > 0)
        {
            if(grid[i][j] == 'Q')
                return false;
            i += 1;
            j -= 1;
        }
        // diagonally down
        i = r + 1, j = c + 1;
        while(i < n && j < n)
        {
            if(grid[i][j] == 'Q')
                return false;
            i += 1;
            j += 1;
        }

        return true;

    }
    void DFSHelper(vector<string>& grid, int i, int n)
    {
        if(i == n)
        {
            sols.push_back(grid);
            return;
            // return true;
        }
        for(int c = 0; c < grid[i].size(); c++)
        {
            if(IsValid(grid, i, c))
            {
                grid[i][c] = 'Q';
                DFSHelper(grid, i + 1, n);
                grid[i][c] = '.';
            }
        }
        // return false;
        
    }
    int totalNQueens(int n) {
        string s = "";
        for(int i = 0; i < n; i++)
            s.push_back('.');
        tempgrid = vector<string>(n, s);
        DFSHelper(tempgrid, 0, n);
        return sols.size();
    }
};
// @lc code=end

