/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> sum3(vector<int>& a, int st, int en, int target)
    {
        vector<vector<int>> temp = {};
        // int j = st + 1;
        // for(j; j < en; j++)
        // {
        //     int i = st;
        //     int k = en;
        //     while(i < j && j < k)
        //     {
        //         int s = a[i] + a[j] + a[k];
        //         if(s < target)
        //         {
        //             i++;
        //         }
        //         else if(s > target)
        //         {
        //             k--;
        //             // if(k == j) break;
        //             // continue;
        //         }
        //         else if(s == target)
        //         {
        //             temp.push_back({a[i], a[j], a[k]});
        //             while(a[i] == a[i + 1]) i++;
        //             while(a[k] == a[k - 1]) k--;
        //             i++, k--;
        //             continue;
        //         }
        //     }
        // }

        for(int i = st; i <= en - 2; i++)
        {
            if(i > st && a[i] == a[i - 1]) continue;
            int j = i + 1;
            int k = en;
            while(j < k)
            {
                int s = a[i] + a[j] + a[k];
                if(s > target) k--;
                else if(s < target) j++;
                else if(s == target)
                {
                    temp.push_back({a[i], a[j], a[k]});
                    while(j < k && a[j] == a[j + 1]) j++;
                    while(j < k && a[k] == a[k - 1]) k--;
                    j++, k--;
                }
            }
        }
        return temp;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++)
        {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            auto temp = sum3(nums, i + 1, nums.size() - 1, target - nums[i]);
            if(!temp.empty())            
            {
                for(auto k : temp)
                {
                    ans.push_back(k);
                    ans[ans.size() - 1].push_back(nums[i]);
                    sort(ans[ans.size() - 1].begin(), ans[ans.size() - 1].end());
                }
            }
            // return ans;
        }
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
    vector<int> a = {2,2,2,2};
    Solution sol;
    vector<vector<int>> ans = sol.fourSum(a, 8);
    return 0;
}