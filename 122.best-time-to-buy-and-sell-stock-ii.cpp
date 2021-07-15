/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution {
public:
    int ans;
    void Help(vector<int>& a, int s)
    {
        if(s >= a.size()) return;
        int st = -1;
        int en = a.size() - 1;
        for(int i = s; i < a.size() - 1; i++)
        {
            if(a[i + 1] > a[i])
            {
                st = i;
                break;
            }
        }
        if(st == -1) return;
        else
        {
            for(int i = st + 1; i < a.size() - 1; i++)
            {
                if(a[i + 1] < a[i])
                {
                    en = i;
                    break;
                }
            }
        }
        if(en == -1) return;
        else
        {
            ans += a[en] - a[st];
            Help(a, en + 1);
        }

    }
    int maxProfit(vector<int>& prices) {
        ans = 0;
        if(prices.size() <= 1) return 0;
        if(prices.size() == 2) return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        Help(prices, 0);
        // for(int i = 0; i < prices.size() - 1; i++)
        // {
        //     ans += prices[i + 1] - prices[i] > 0 ? prices[i + 1] - prices[i] : 0;
        // }
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
    vector<int> a = {1, 2, 3, 4, 5};
    Solution sol;
    cout << sol.maxProfit(a);
    return 0;
}