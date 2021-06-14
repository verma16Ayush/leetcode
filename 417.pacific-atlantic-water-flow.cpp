/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

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

// ~600ms. I can do better than this.

/*
*/
class Solution 
{
public:
    vector<pair<int, int>> dir;
    vector<vector<bool>> ToP;
    vector<vector<bool>> ToA;

    bool DfsToP(vector<vector<int>>& heights, int i, int j)
    {
        if(i == 0 || j == 0) return ToP[i][j] = 1;
        // if(i == heights.size() || j == heights[0].size()) return ToP[i][j] = 0;
        if(heights[i][j] != -1)
        {
            for(auto d : dir)
            {
                if(i + d.first < heights.size() && j + d.second < heights[0].size() && heights[i + d.first][j + d.second] <= heights[i][j])
                {
                    int k = heights[i][j];
                    heights[i][j] = -1;
                    ToP[i][j] = ToP[i][j] || DfsToP(heights, i + d.first, j + d.second);
                    heights[i][j] = k;
                }
            }
        }
        return ToP[i][j];
    }
    bool DfsToA(vector<vector<int>>& heights, int i, int j)
    {
        // if(i == 0 || j == 0) return ToP[i][j] = 0;
        if(i == heights.size() - 1 || j == heights[0].size() - 1) return ToA[i][j] = 1;
        if(heights[i][j] != -1)
        {
            for(auto d : dir)
            {
                if(i + d.first >= 0 && j + d.second >= 0 && heights[i + d.first][j + d.second] <= heights[i][j])
                {
                    int k = heights[i][j];
                    heights[i][j] = -1;
                    ToA[i][j] = ToA[i][j] || DfsToA(heights, i + d.first, j + d.second);
                    heights[i][j] = k;
                }
            }
        }
        return ToA[i][j];
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        ToP = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size(), false));
        ToA = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size(), false));
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < heights.size(); i++)
        {
            for(int j = 0; j < heights[0].size(); j++)
            {
                if(!ToP[i][j]) DfsToP(heights, i, j);
                if(!ToA[i][j]) DfsToA(heights, i, j);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < ToP.size(); i++)
        {
            for(int j = 0; j < ToP[0].size(); j++)
            {
                if(ToP[i][j] && ToA[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
//     {

//     }
// };

// @lc code=end


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution sol;
    vector<vector<int>> ans = sol.pacificAtlantic(a);

    return 0;
}