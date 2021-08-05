/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> solve(vector<int>);
};
vector<int> Solution::solve(vector<int> A) {
    vector<int> a((int)1e5);
    // int c1 = 0;
    // for(int i : A) 
    // {
    //     a[i] += 1;
    //     c1 += i == 1;
    // }
    // if(a[1]) a[1] = A.size();
    // for(int i = 2; i < a.size(); i++)
    // {
    //     if(a[i])
    //     {
    //         for(int k = 2 * i; k < a.size(); k += i)
    //         {
    //             if(a[k]) 
    //             {
    //                 a[i] += a[k];
    //                 a[k] += a[i];
    //             }
    //         }
    //     }
    // }
    for(int i : A) a[i]++;
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < A.size(); i++)
    {
        mp[A[i]].push_back(i);
    }
    
    vector<int> ans(A.size());
    for(int i = 0; i < ans.size(); i++)
    {
        if(A[i] == 1)
        {
            ans[i] = A.size() - 1;
            continue;
        }
        ans[i] += a[A[i]] - 1;
        for(int k = 2 * A[i]; k < a.size(); k += A[i])
        {
            ans[i] += a[k];
            if(mp.find(k) != mp.end())
            {
                for(int i  : mp[k])
                {
                    ans[i]++;
                }
            }
        }
        ans[i] += a[1];

    }
    return ans;

    // vector<int> ans(A.size());
    // for(int i = 0; i < A.size(); i++)
    // {

    //     for(int k = 0; k < A.size(); k++)
    //     {
    //         if(k == i) continue;
    //         if(A[i] % A[k] == 0 || A[k] % A[i] == 0)
    //         {
    //             ans[i] += 1;
    //         }
    //     }
    // }

    // return ans;

}
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> x = {21, 19, 28, 23, 12, 22, 3, 13, 6, 32, 30, 21, 34, 1, 5, 22, 21, 1, 20, 21, 4, 21 , 21, 20, 16, 8, 21, 7, 4, 15, 8, 11, 13, 32, 35}; // {3, 2, 2, 1}
    // vector<int> x = {2, 2, 4, 4};
    auto ans = Solution().solve(x);
    return 0;
}
