/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int getsum(int n)
    {
        int s = 0;
        while(n)
        {
            int d = n % 10;
            s += d * d;
            n = n / 10;
        }
        return s;
    }
    bool help(int n, unordered_set<int>& visited)
    {
        int fast = n, slow = n;
        do
        {
            slow = getsum(slow);
            fast = getsum(fast);
            fast = getsum(fast);
            if(fast == 1 || slow == 1) return true;
        } while (fast != slow);
        return false;
        
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        return help(n, st);
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
    cout << sol.isHappy(2);
    return 0;
}