/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> u_mp;
        for(int i = 0; i < nums.size(); i++)
            u_mp[nums[i]].push_back(i);
        for(auto pair : u_mp)
        {
            if(pair.first == target - pair.first)
            {
                if(pair.second.size() >= 2)
                    return {pair.second[0], pair.second[1]};
            }
            else
            {
                if(u_mp.find(target - pair.first) != u_mp.end())
                {
                    return {pair.second[0], u_mp[target - pair.first][0]};
                }
            }
        }
        return {};
    }
};
// @lc code=end

