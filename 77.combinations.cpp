/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void help(int n, vector<int> temp, int k, int i)
    {
        if(i > n) return;
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for(int j = i + 1; j <= n; j++)
        {
            temp.push_back(j);
            help(n, temp, k, j);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans = vector<vector<int>>();
        help(n, vector<int>(), k, 0);
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
    auto ans = Solution().combine(4, 2);
    return 0;
}