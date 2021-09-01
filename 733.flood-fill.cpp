/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<pair<int, int>> dir;
    void dfs(vector<vector<int>>& img, int i, int j, int ori, int tg)
    {
        if(i < 0 || j < 0 || i >= img.size() || j > img[0].size() || img[i][j] != ori)
            return;
        for(auto d : dir)
        {
            // img[i][j] = -1;
            dfs(img, i + d.first, j + d.second, ori, tg);
            img[i][j] = tg;
        }
    }
    vector<vector<int>> floodFill(  vector<vector<int>>& image, 
                                    int sr, int sc, int newColor) 
    {
        if(image[sr][sc] == newColor) return image;
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{0, 0, 0}, {0, 1, 1}};
    vector<vector<int>> ans = Solution().floodFill(a, 1, 1, 1);
    return 0;
}