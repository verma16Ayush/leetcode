#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = (int)(1e9 + 7);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums)
            pq.push(i);
        while(k)
        {
            int top = pq.top();
            pq.pop();
            top++;
            k--;
            pq.push(top);
        }
        int prod = 1;
        while(pq.size())
        {
            prod *= pq.top();
            prod %= mod;
            pq.pop();
        }
        return prod;
    }
};