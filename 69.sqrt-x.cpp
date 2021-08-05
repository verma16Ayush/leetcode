/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x < 4) return 1;
        int s = 0, e = x;
        int ans;
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(mid == x / mid)
            {
                ans = mid;
                break;
            }
            else if(x / mid > mid)
            {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;

        }
        return ans;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout << Solution().mySqrt(2147395599);
    return 0;
}
