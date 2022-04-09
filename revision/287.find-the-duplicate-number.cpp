/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slo = 0;
        int fas = 0;
        do
        {
            slo = nums[slo];
            fas = nums[nums[fas]];
        }
        while(slo != fas);
        slo = 0;
        while(slo != fas)
        {
            slo = nums[slo];
            fas = nums[fas];
        }
        return slo;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,3,4,2,2};
    cout << Solution().findDuplicate(a);
    return 0;
}

