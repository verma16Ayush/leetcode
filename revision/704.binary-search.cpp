/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, en = nums.size() - 1;
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(target == nums[mid])
                return mid;
            if(target > mid)
                st = mid + 1;
            else
                en = mid - 1;
        }
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
    vector<int> a = {-1,0,3,5,9,12};
    cout << Solution().search(a, 9) << endl;
    return 0;
}
