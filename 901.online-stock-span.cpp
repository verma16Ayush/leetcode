/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class StockSpanner {
    vector<pair<int, int>> prices;
public:
    StockSpanner() : prices(vector<pair<int, int>>()) {}
    
    int next(int price) {
        int k = 0;
        while(prices.size() && price >= prices.back().first)
        {
            k += prices.back().second;
            prices.pop_back();
        }
        prices.push_back({price, k + 1});
        return prices.back().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

