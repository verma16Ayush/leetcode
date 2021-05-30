/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n == 1) return true;
        int flag = 0;
        for(int i = 0; i <= 31; i++)
        {
            if((1 << i) & n)
            {
                if(i % 2 == 1) return false;
                if(i % 2 == 0)
                {
                    if(flag) return false;
                    else flag = 1;
                }
            }
        }
        return flag;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    cout << sol.isPowerOfFour(5) << endl;
    return 0;
}
