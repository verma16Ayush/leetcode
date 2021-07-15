/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int binSearch(vector<int>& nums, int s, int e, int val)
    {
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(nums[mid] == val) return mid;
            else if(val < nums[mid]) e = mid - 1;
            else if(val > nums[mid]) s = mid + 1;
        }
        return s;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size() - 1, target);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1, 3, 5, 6};
    cout << Solution().searchInsert(a, 2);
    return 0;
}