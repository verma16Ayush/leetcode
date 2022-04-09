/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for(int i : stones)
            pq.push(i);
        while(pq.size() > 1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top1 != top2)
            {
                pq.push(abs(top1 - top2));
            }
        }
        return pq.size() ? pq.top() : 0;
    }
};
// @lc code=end

