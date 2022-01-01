/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int mx = 0;
    int SearchPlus(vector<vector<int>>& a, int i, int j)
    {
        int res = INT32_MAX;
        int r = i, c = j;
        // down
        int s = 0;
        while(r < a.size() && a[r][c] == 1) r++, s++;
        res = min(res, s);

        // up
        s = 0;
        r = i, c = j;
        while(r >= 0 && a[r][c] == 1) r--, s++;
        res = min(res, s);

        // right
        s = 0;
        r = i, c = j;
        while(c < a[0].size() && a[r][c] == 1) c++, s++;
        res = min(res, s);

        // left
        s = 0;
        r = i, c = j;
        while(c >= 0 && a[r][c] == 1) c--, s++;
        res = min(res, s);

        return res;
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> a(n, vector<int>(n, 1));
        for(auto i : mines)
            a[i[0]][i[1]] = 0;
        
        int mx = 0;
        for(int i = 0; i < a.size(); i++)
            for(int j = 0; j < a[0].size(); j++)
                if(a[i][j]) 
                    mx = max(mx, SearchPlus(a, i, j));
        
        return mx;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{0, 0}, {1, 1}};
    cout << Solution().orderOfLargestPlusSign(2, a);
    return 0;
}