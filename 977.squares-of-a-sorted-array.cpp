/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void MergeArr(vector<int>& a, vector<int>& b, vector<int>& ans)
    {
        int i = 0, j = 0;
        int k = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] < b[j])
                ans[k++] = a[i++];
            else
                ans[k++] = b[j++];
        }

        while (i < a.size())
            ans[k++] = a[i++];
        
        while(j < b.size())
            ans[k++] = b[j++];
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> ng;
        vector<int> ps;
        
        for(int& i : nums)
        {
            if(i < 0)
                ng.push_back(i * i);
            else
                ps.push_back(i * i);
        }
        reverse(ng.begin(), ng.end());
        MergeArr(ng, ps, ans);
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
//     vector<int> a = 
//     return 0;
// }