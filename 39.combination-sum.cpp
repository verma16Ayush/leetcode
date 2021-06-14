/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void SubsetSum(vector<int> a, int target, int n, vector<int> temp)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(n == 0) return;
        if(a[n - 1] <= target)
        {
            temp.push_back(a[n - 1]);
            SubsetSum(a, target - a[n - 1], n, temp);
            temp.pop_back();
            // SubsetSum(a, target, n - 1, temp);
            // return;
        }
        SubsetSum(a, target, n - 1, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        ans = vector<vector<int> >();
        temp = vector<int> ();
        SubsetSum(candidates, target, candidates.size(), temp);
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {2, 3, 6, 7};
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(a, 7);
    return 0;
}
