/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct cmp
{
    bool operator()(int& a, int& b)
    {
        return a < b;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};
// @lc code=end

