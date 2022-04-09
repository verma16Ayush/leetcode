/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<pair<int, int>> dir;
    Solution() {
        dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    }
    bool DFSHelper(vector<vector<char>>& board, int i, int j, int k , string word)
    {
        if(k == word.size())
            return true;
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0)
            return false;
        if(board[i][j] != word[k])
            return false;
        char temp = board[i][j];
        board[i][j] = '*';
        for(auto d : dir)
            if(DFSHelper(board, i + d.first, j + d.second, k + 1, word))
                return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                    res = res || DFSHelper(board, i, j, 0, word);
            }
        }
        return res;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<char>> a = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << Solution().exist(a, "ABCCED") << endl;
    return 0;
}