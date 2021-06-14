/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
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
            SubsetSum(a, target - a[n - 1], n - 1, temp);
            temp.pop_back();
            // SubsetSum(a, target, n - 1, temp);
            // return;
        }
        SubsetSum(a, target, n - 1, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        ans = vector<vector<int> >();
        temp = vector<int> ();
        SubsetSum(candidates, target, candidates.size(), temp);
        return ans;
    }
};
// @lc code=end

