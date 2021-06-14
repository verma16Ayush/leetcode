/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        int d1 = a[0] * a[0] + a[1] * a[1];
        int d2 = b[0] * b[0] + b[1] * b[1];
        
        return d1 < d2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto pt : points)
        {
            pq.push(pt);
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(pq.size())
        {
            ans.push_back(pq.top());
            pq.pop();
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
    vector<vector<int>> a = {{-1, 3}, {2, 2}};
    Solution sol;
    sol.kClosest(a, 1);

    return 0;
}
