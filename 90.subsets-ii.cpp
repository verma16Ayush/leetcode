/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<string> hash;
    bool HashAndCheck(vector<int>& temp)
    {
        string checksum = "";
        sort(temp.begin(), temp.end());
        for(int i : temp)
        {
            checksum += (char)(10 + i);
        }
        if(hash.find(checksum) == hash.end())
        {
            hash.insert(checksum);
            return false;
        }
        return true;
    }
    void GenSubs(vector<int>& a, int i, vector<int> temp)
    {
        if(i == a.size())
        {
            if(!HashAndCheck(temp))
                ans.push_back(temp);
            return;
        }

        temp.push_back(a[i]);
        GenSubs(a, i + 1, temp);
        temp.pop_back();
        GenSubs(a, i + 1, temp);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans = vector<vector<int>>();
        GenSubs(nums, 0, vector<int>());
        reverse(ans.begin(), ans.end());
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
    vector<int> a = {1, 2, 2};
    Solution sol;
    vector<vector<int>> ans = sol.subsetsWithDup(a);
    return 0;
}