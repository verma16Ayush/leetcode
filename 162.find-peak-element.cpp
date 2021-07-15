/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int get(vector<int>& a, int i)
    {
        if(i == -1 || i == a.size())
            return INT32_MIN;
        return a[i];
    }

    int BinSearch(vector<int>& a)
    {
        int s = 0, e = a.size() - 1;
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(get(a, mid) > get(a, mid + 1) && get(a, mid) > get(a, mid  - 1))
                return mid;
            else if(get(a, mid + 1) > get(a, mid)) 
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        return BinSearch(nums);
    }
};
// @lc code=end

