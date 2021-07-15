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
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        long long j = 0, k = a.size() - 1;
        long long mn = INT32_MAX;
        for(int i = 1; i < a.size() - 1; i++)
        {
            j = 0, k = a.size() - 1;
            long long mnc = a[j] + a[i] + a[k];
            while(j < i && i < k)
            {
                mn = min(mn, mnc, [target](const long long& a, const long long& b)->bool{
                    return abs(a - target) < abs(b - target);
                });
                if(mnc > target)
                {
                    k--;
                    if(k == i) break;
                    mnc = a[i] + a[j] + a[k];
                    continue;
                }
                if(mnc < target)
                {
                    j++;
                    if(j == i) break;
                    mnc = a[i] + a[j] + a[k];
                    continue;
                }
                if(mnc == target) return target;
            }
            mn = min(mn, mnc, [target](const long long& a, const long long& b)->bool{
                return abs(a - target) < abs(b - target);
            });
        }
        return mn;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {0,2,1,-3};
    Solution sol;
    cout << sol.threeSumClosest(a, 1);
    return 0;
}