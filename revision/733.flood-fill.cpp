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
    Solution() {
        dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    }
    void DfsHelper(vector<vector<int>>& img, int i, int j, int nc, int oc)
    {
        if(i < 0 || j < 0 || i >= img.size() || j >= img[0].size())
            return;
        if(img[i][j] != oc)
            return;
        img[i][j] = nc;
        for(auto d : dir)
            DfsHelper(img, i + d.first, j + d.second, nc, oc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        DfsHelper(image, sr, sc, newColor, image[sr][sc]);
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
    vector<vector<int>> a = {
        {0,0,0}, 
        {0,1,1}
    };
    Solution().floodFill(a, 1, 1, 1);

    return 0;
}