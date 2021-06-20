#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
    {
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0) return;
        if(grid2[i][j] == 1)
        {
            grid[i][]
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}