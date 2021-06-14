/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& a) 
    {
        int slow = 0, mid = 0, fast = a.size() - 1;
        while(mid <= fast)
        {
            if(a[mid] == 0)
            {
                swap(a[mid++], a[slow++]);
                continue;
            }
            if(a[mid] == 2)
            {
                swap(a[mid], a[fast--]);
                continue;
            }
            if(a[mid] == 1)
            {
                mid++;
                continue;
            }
        }
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
    vector<int> a = {2, 0, 1};
    sol.sortColors(a);

    return 0;
}