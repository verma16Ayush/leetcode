/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int Pivot(vector<int>& a, int l, int r)
    {
        int piv = r;
        int i = l, j = l;
        while(j < r)
        {
            if(a[j] < a[piv])
            {
                swap(a[j], a[i]);
                i++;
            }
            j++;
        }
        swap(a[piv], a[i]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums.begin(), nums.end(), default_random_engine(time(0)));
        int l = 0, r = nums.size() - 1;
        int fi = nums.size() - k;
        while(l <= r)
        {
            int piv = Pivot(nums, l, r);
            if(piv == fi)
                return nums[piv];
            else if(piv < fi)
                l = piv + 1;
            else
                r = piv - 1;
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
    vector<int> a = {3,2,1,5,6,4};
    cout << Solution().findKthLargest(a, 2);
    return 0;
}