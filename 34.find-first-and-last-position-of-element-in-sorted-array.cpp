/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int GetHigh(const vector<int>& a, int target)
    {
        int low = 0;
        int high = a.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(a[mid] == target && (mid == a.size() - 1 || a[mid + 1] > target))
            {
                return mid;
            }
            if(a[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    int GetLow(const vector<int>& a, int target)
    {
        int low = 0;
        int high = a.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(a[mid] == target && (mid == 0 || a[mid - 1] < target))
            {
                return mid;
            }
            if(a[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& a, int target) 
    {
        int l = GetLow(a, target);
        int h = GetHigh(a, target);
        return {l, h};
    }
};
// @lc code=end

