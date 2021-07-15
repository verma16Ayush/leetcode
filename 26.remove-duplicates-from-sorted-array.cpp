/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;
        if(nums.size() <= 1) return nums.size();
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                nums[++i] = nums[j];
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
    vector<int> a = {1, 1, 2, 2, 3};
    int n = Solution().removeDuplicates(a);
    for(int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    return 0;
}