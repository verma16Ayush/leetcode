/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> keyset;
        for(int i = 0; i < nums.size(); i++) 
        {
            mp[nums[i]].push_back(i);
            keyset.insert(nums[i]);
        }
        if(target % 2 == 0&& mp.find(target / 2) != mp.end() && mp[target / 2].size() > 1) return vector<int>() = {mp[target / 2][0], mp[target / 2][1]};
        else
        {
            for(auto i : keyset)
            {
                if(mp.find(i) != mp.end() && mp.find(target - i) != mp.end()) return {mp[i][0], mp[target - i][0]};
            }
        }
        return vector<int>();
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {3,2,4};
    auto temp = Solution().twoSum(a, 6);
    return 0;
}
