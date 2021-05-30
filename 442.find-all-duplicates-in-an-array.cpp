/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> a;
        a.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            int in = abs(nums[i]) - 1;
            if(nums[in] < 0) a.push_back(in + 1);
            nums[in] = -nums[in];
        }
        return a;
    }
};
// @lc code=end
// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
    
//     return 0;
// }
