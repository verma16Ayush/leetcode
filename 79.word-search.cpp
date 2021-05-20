/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> dir;
    bool dfs(vector<vector<char>>& board, int i, int j, string w, int m)
    {
        if(m == w.length()) return true; 
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0) return false; 
        if(board[i][j] == w[m])
        {
            char c = board[i][j];
            board[i][j] = '*'; // lmao lol 
            for(auto d : dir)
            {
                if(dfs(board, i + d.first, j + d.second, w, m + 1)) return true;
            }
            board[i][j] = c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool res = false;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0]) res = res || dfs(board, i, j, word, 0); 
            }
        }
        return res;
    }
};
// @lc code=end

