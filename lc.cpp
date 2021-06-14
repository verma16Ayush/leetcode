#include <bits/stdc++.h>
using namespace std;

void PrintMat(vector<vector<int>> a)
{
    for(auto i : a)
    {
        for(int j : i) cout << j << " ";
        cout << endl;
    }
}
class Solution {
public:


    bool ValidateDiag(vector<vector<int>>& grid, int i, int j, int k, int val)
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int ii = 0; ii < k; ii++)
        {
            sum1 += grid[i + ii][j + ii];
            sum2 += grid[i + ii][j + k - 1 - ii];
        }
        return sum1 == val && sum2 == val;
    }
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        vector<vector<int>> prefix_row(grid.size(), vector<int>(grid[0].size() + 1, 0));
        vector<vector<int>> prefix_col(grid.size() + 1, vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                prefix_row[i][j + 1] = grid[i][j];
                prefix_row[i][j + 1] += prefix_row[i][j];
            }
        }
        for(int j = 0; j < grid[0].size(); j++)
        {
            for(int i = 0; i < grid.size(); i++)
            {
                prefix_col[i + 1][j] = grid[i][j];
                prefix_col[i + 1][j] += prefix_col[i][j];
            }
        }

        int max_size = min(grid.size(), grid[0].size());

        int ans = 1;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                for(int k = 2; k <= max_size && i + k < grid.size() && j + k <= grid[0].size(); k++)
                {
                    int sumcol = abs(prefix_col[i][j] - prefix_col[i][j + k]);
                    int sumrow = abs(prefix_row[i][j] - prefix_row[i + k][j]);
                    if(sumrow == sumcol && ValidateDiag(grid, i, j, k, sumrow));
                    ans = k;
                }
            }
        }
        return ans;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    Solution sol;
    cout << sol.largestMagicSquare(a);
    return 0;
}
