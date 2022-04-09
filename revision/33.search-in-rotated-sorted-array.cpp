/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    int SearchPivot(const vector<int>& a)
    {
        int st = 0, en = a.size() - 1;
        int n = a.size();
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(a[mid] < a[(mid - 1 + n) % n] && a[mid] < a[(mid + 1) % n])
                return mid;
            else if(a[en] < a[mid])
                st = mid + 1;
            else 
                en = mid - 1;
        }
        return -1;
    }
    
    int BinSearch(const vector<int>& nums, int st, int en, int target)
    {
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                st = mid + 1;
            else
                en = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = SearchPivot(nums);
        int k = BinSearch(nums, 0, (pivot - 1 + n) % n, target);
        int l = BinSearch(nums, (pivot) % n, nums.size() - 1, target);
        if(k != -1)
            return k;
        if(l != -1)
            return l;
        return -1;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,2};
    cout << Solution().search(a, 2) << endl;
    return 0;
}