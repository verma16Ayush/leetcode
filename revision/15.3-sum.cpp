/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i = 0, j = i + 1, k = nums.size() - 1;
        for(i; i < nums.size() - 2; i++)
        {
            j = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                int cursum = nums[i] + nums[j] + nums[k];
                if(cursum == 0)
                {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    ans.push_back(trip);
                    while(trip[1] == nums[j] && j < k)
                        j++;
                    while(trip[2] == nums[k] && j < k)
                        k--;
                }
                else if(cursum > 0)
                    k--;
                else 
                    j++;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};
// @lc code=end

