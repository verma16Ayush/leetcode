/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int GetHigh(const vector<int>& a, int target)
    {
        int st = 0, en = a.size() - 1;
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(a[mid] == target && (mid == a.size() - 1 || a[mid + 1] > target))
                return mid;
            else if(a[mid] > target)
                en = mid - 1;
            else
                st = mid + 1;
        }
        return -1;
    }

    int GetLow(const vector<int>& a, int target)
    {
        int st = 0, en = a.size() - 1;
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(a[mid] == target && (mid == 0 || a[mid - 1] < target))
                return mid;
            else if(a[mid] < target)
                st = mid + 1;
            else
                en = mid - 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size())
            return {-1, -1};
        return {GetLow(nums, target), GetHigh(nums, target)};
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}

