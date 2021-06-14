/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:

//     void NextPermute(vector<int>& a)
//     {
//         if(is_sorted(a.rbegin(), a.rend()))
//         {
//             reverse(a.begin(), a.end());
//             return;
//         }
//         int i = 0;
//         for(i = a.size() - 1; i - 1 >= 0; i--)
//         {
//             if(a[i - 1] >= a[i]) continue;
//             else break;
//         }
//         int k = i - 1;
//         for(int j = a.size() - 1; j > k; j--)
//         {
//             if(a[j] > a[k])
//             {
//                 swap(a[j], a[k]);
//                 break;
//             }
//         }
//         reverse(&a[k + 1], &a[a.size()]);
//     }
//     vector<vector<int>> permute(vector<int>& nums) 
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         do
//         {
//             NextPermute(nums);
//             vector<int> temp = nums;
//             ans.push_back(temp);
//         }
//         while(!is_sorted(nums.begin(), nums.end()));
//         return ans;
//     }
// };
class Solution
{
public:
    vector<vector<int>> ans;
    bool Contains(vector<int> a, int i)
    {
        for(int j : a) if(i == j) return 1;
        return 0;
    }

    void Recur(vector<int>& a, int n, vector<int> rev)
    {
        if(n == a.size())
        {
            ans.push_back(rev);
        }
        for(int i : a)
        {
            if(!Contains(rev, i))
            {
                rev.push_back(i);
                Recur(a, n + 1, rev);
                rev.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& a)
    {
        vector<int> rev;
        Recur(a, 0, rev);
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
    vector<int> a = {1, 2, 3};
    Solution sol;
    vector<vector<int>> ans = sol.permute(a);
    return 0;
}

