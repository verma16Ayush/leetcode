/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    // int f[(int)1e5 + 1];
    vector<int> findDisappearedNumbers(vector<int>& a) 
    {
        int n = a.size();
        for(int i = 0; i < n; i++)
        {
            int in = abs(a[i]) - 1;
            a[in] = -abs(a[in]);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= 0) ans.push_back(i + 1);
        }
        return ans;
    }
};
// @lc code=end
// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     vector<int> a = {4, 3, 2, 7, 8, 2, 3, 1};
//     Solution sol;
//     vector<int> ans = sol.findDisappearedNumbers(a);
//     for(int i : ans) cout << i << " ";
//     cout << endl;
//     return 0;
// }

