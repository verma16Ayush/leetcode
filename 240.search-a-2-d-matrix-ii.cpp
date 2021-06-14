/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) 
    {
       int i = 0;
       int j = a[0].size() - 1;
       while(i < a.size() && j >= 0)
       {
           if(target == a[i][j]) return 1;
           else if(target < a[i][j]) j--;
           else if(target > a[i][j]) i++;
       }
       return 0;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector<vector<int>> a(5, vector<int>(5, 0));
    for(vector<int>& i : a)
    {
        for(int& j : i) cin >> j;
    }
    Solution sol;
    cout << sol.searchMatrix(a, 5);
    return 0;
}