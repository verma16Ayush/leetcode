/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0] == val ? 0 : 1;
        int i = 0, j = nums.size() - 1;
        while(j >= 0 && nums[j] == val) j--;
        while(i <= j)
        {
            if(nums[i] == val)
            {
                swap(nums[i], nums[j]);
                j--;
                while(j >= i && nums[j] == val) j--;
            }
            i++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == val) return i;
        }
        return nums.size();
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {4,2,0,2,2,1,4,4,1,4,3,2};
    Solution sol;
    int n = sol.removeElement(a, 4);
    
    return 0;
}

