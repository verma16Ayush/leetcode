/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subs;
    
    void GenSubs(vector<int>& n, vector<int> set, int sz)
    {
        if(sz == 0)
        {
            subs.push_back(set);
            set.clear();
            return;
        }
        set.push_back(n[sz - 1]);
        GenSubs(n , set, sz - 1);
        set.pop_back();
        GenSubs(n, set, sz - 1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> set;
        GenSubs(nums, set, nums.size());
        return subs;
    }
};
// @lc code=end

