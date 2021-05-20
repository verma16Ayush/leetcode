/** 
 *
 * @author - Ayush
 * @title - pacificatlantic.cpp
 * @createdOn - 2021-04-08 15:07 Hrs
 * 
 **/
#include <iostream>
#include <bits/stdc++.h>
#define nl '\n'
#define int ll
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
typedef long long ll;
using namespace std;

void PrintMat(vector<vector<int>>& a)
{
    for(auto i : a)
    {
        for(int j : i) cout << j << " ";
        cout << nl;
    }
    cout << nl << nl;
}

struct Flows
{
    int toP;
    int toA;
    Flows(int a = -1, int p = -1)
    {
        toA = a;
        toP = p;
    }
};
class Solution 
{
public:
    int dp[300][300][2]; // dp[r][c][0] = atlantic, dp[r][c][1] = pacific
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfsToA(vector<vector<int>>& heights, int R, int C, int r, int c)
    {
        if(r >= R - 1 || c >= C - 1) return dp[r][c][0] = 1;
        if(dp[r][c][0] != -1) return dp[r][c][0];
        if(heights[r][c] == -1) return dp[r][c][0] = 0;
        int temp = heights[r][c];
        heights[r][c] = -1;
        for(auto d : dir)
        {
            if(r + d.first >= 0 && c + d.first >= 0 && r + d.first < R && c + d.second < C && heights[r + d.first][c + d.second] <= temp) dp[r][c][0] = dfsToA(heights, R, C, r + d.first, c + d.second);
        }
        heights[r][c] = temp;
        return dp[r][c][0];
    }
    int dfsToP(vector<vector<int>>& heights, int R, int C, int r, int c)
    {
        if(r <= 0 || c <= 0) return dp[r][c][1] = 1;
        if(dp[r][c][1] != -1) return dp[r][c][1];
        if(heights[r][c] == -1) return dp[r][c][1] = 0;
        int temp = heights[r][c];
        heights[r][c] = -1;
        for(auto d : dir)
        {
            if(r + d.first >= 0 && c + d.first >= 0 && r + d.first < R && c + d.second < C && heights[r + d.first][c + d.second] <= temp) dp[r][c][1] = dfsToP(heights, R, C, r + d.first, c + d.second);
        }
        heights[r][c] = temp;
        return dp[r][c][1];
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int R = heights.size();
        int C = heights[0].size();
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                dfsToP(heights, R, C, i, j);
                dfsToA(heights, R, C, i, j);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(dp[i][j][0] && dp[i][j][1]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for(auto& i : a)
    {
        for(auto& j : i)
        {
            cin >> j;
        }
    }
    Solution* sol = new Solution();
    vector<vector<int>> ans = sol->pacificAtlantic(a);
    return 0;
}

