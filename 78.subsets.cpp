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

// trying another approach
// class Solution
// {
// public:
//     vector<vector<int>> ans;
//     void helper(vector<int>& a, int st, vector<int> temp)
//     {
//         ans.push_back(temp);
//         for(int i = st; i < a.size(); i++)
//         {
//             temp.push_back(a[i]);
//             helper(a, st + 1, temp);
//             temp.pop_back();
//         }
//         return;
//     }
//     vector<vector<int>> subsets(vector<int>& a)
//     {
//         ans = vector<vector<int>>();
//         helper(a, 0, vector<int>());
//         return ans;
//     }
// };
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1, 2, 3};
    Solution sol;
    sol.subsets(a);
    return 0;
}