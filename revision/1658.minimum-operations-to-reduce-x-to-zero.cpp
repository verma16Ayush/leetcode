/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0, [&](int& a, int& b)->int{
            return a + b;
        });
        if(sum == x)
            return nums.size();
        int target = sum - x;
        int st = 0, en = 0;
        int maxLen = 1;
        int found = 0;
        int runningSum = 0;

        for(en = 0; en < nums.size(); en++)
        {
            runningSum += nums[en];
            while(st <= en && runningSum > target)
            {
                runningSum -= nums[st];
                st++;
            }
            if(runningSum == target)
            {
                found = 1;
                maxLen = max(maxLen, en - st + 1);
            }
        }
        return found ? nums.size() - maxLen : -1;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    cout << Solution().minOperations(a, 134365);
    return 0;
}