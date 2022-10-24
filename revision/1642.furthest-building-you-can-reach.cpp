/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < heights.size() - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            
            if(diff > 0)
                pq.push(diff);
            
            if(pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
                if(bricks < 0)
                    return i;
            }
        }
        return heights.size() - 1;
    }
};
// @lc code=end

