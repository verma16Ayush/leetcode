/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;
        if(nums.size() <= 1) return nums.size();
        int k = 0;
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                k = 0;
                nums[++i] = nums[j];
            }
            else
            {
                if(k == 0)
                {
                    nums[++i] = nums[j];
                    k = 1;
                }
            }
            j++;
        }
        return i + 1;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,1,1,2,2,3};
    Solution sol;
    cout << sol.removeDuplicates(a);
    
    return 0;
}