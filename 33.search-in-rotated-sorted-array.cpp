/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivot(vector<int>& a)
    {
        int l = 0;
        int h = a.size() - 1;
        int n = a.size();
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            // very improtant
            if(a[(mid + n - 1) % n] > a[mid] && a[(mid + 1) % n] > a[mid]) return mid;
            else if(a[h] < a[mid])
            {
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return -1;
    }

    int BinSearch(vector<int>& a, int l, int h, int x)
    {
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(a[mid] == x) return mid;
            else if(x > a[mid]) l = mid + 1;
            else if(x < a[mid]) h = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& a, int target) 
    {
        if(a.size() == 1) return a[0] == target ? 0 : -1;
        if(a.size() == 2) return a[0] == target ? 0 : (a[1] == target ? 1 : -1);
        int p = pivot(a);
        int i = BinSearch(a, 0, p - 1, target);
        int j = BinSearch(a, p, a.size() - 1, target);
        return i == -1 ? j : i;
    }
};
// @lc code=end

