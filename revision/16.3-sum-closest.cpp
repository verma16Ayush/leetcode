/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() <= 2)
            return {};
        int closest = INT32_MAX - 1e3;
        int i = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                int cursum = nums[i] + nums[j] + nums[k];
                closest = min(closest, cursum, [&](int a, int b)->bool {
                    return abs(target - a) < abs(target - b);
                });
                if(cursum > target)
                    k--;
                else if(cursum < target) 
                    j++;
                else
                    return cursum;
            }
        }
        return closest;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {0, 2, 1, -3};
    cout << Solution().threeSumClosest(a, 1) << endl;
    return 0;
}
