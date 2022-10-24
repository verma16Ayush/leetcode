/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        for(int i = 0; i < matrix.size(); i++)
        {
            pq.push({matrix[i][0], i, 0});
            if(pq.size() > k)
                pq.pop();
        }
        
        while(k)
        {
            k--;
            auto top = pq.top();
            pq.pop();
            pq.push({matrix[top[1]][top[2] + 1], top[1], top[2] + 1});
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top()[0];
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {
        {3, 2, 5, 6, 7}
    };
    cout << Solution().kthSmallest(a, 1);
    return 0;
}

