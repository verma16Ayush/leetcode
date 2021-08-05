#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
void dfs(vector<vector<int>>& matrix, int i, int j)
{
    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return;
    matrix[i][j] = -1;
    for(auto d : dir)
    {
        if(i + d.first >= 0 && j + d.second >= 0 && i + d.first < matrix.size() && j + d.second < matrix[0].size() && matrix[i + d.first][j + d.second] == 1)
        {
            dfs(matrix, i + d.first, j + d.second);
        }
    }
    return;
}

int numberofislands(vector<vector<int>>& mat)
{
    int c = 0; // numberofislands

    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[0].size(); j++)
        {
            if(mat[i][j] == 1)
            {
                c++;
                dfs(mat, i, j);
            }
        }
    }
    return c;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> mat = {{1,1,0},
 {1,1,0},
 {0,0,1}};
    cout << numberofislands(mat);
    return 0;
}