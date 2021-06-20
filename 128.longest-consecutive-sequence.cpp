/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> mp;
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        mp = unordered_map<int, int>();
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int res = 1;

        for(int i : nums)
        {
            if(mp.find(i) == mp.end()) continue;
            int prev = i - 1;
            int next = i + 1;
            mp.erase(i);
            while(mp.find(prev) != mp.end()) mp.erase(prev--);
            while(mp.find(next) != mp.end()) mp.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
// @lc code=end

