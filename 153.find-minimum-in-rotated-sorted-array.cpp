/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int FindPivot(vector<int>& a)
    {
        int st = 0;
        int en = a.size() - 1;
        int n = a.size();
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            cout << mid << " " << a[mid] << endl;
            if(a[mid] < a[(mid + 1) % n] && a[mid] < a[(mid - 1 + n) % n]) return mid;
            else if(a[en] < a[mid]) st = mid + 1;
            else en = mid - 1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return nums[FindPivot(nums)];
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {4,5,6,7,0,1,2};
    cout << Solution().findMin(a);
    return 0;
}