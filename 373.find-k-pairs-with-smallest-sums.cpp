/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, 
                                        vector<int>& nums2, int k) 
    {
        vector<vector<int>> ans;
        priority_queue< pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>> > pq;

        for(int i = 0; i < nums1.size(); i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});

        long long sz = min((long long)k, (long long)nums1.size() * (long long)nums2.size());
        while(ans.size() != sz)
        {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first, j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});
            if(j + 1 != nums2.size()) pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
        return ans;
    }
};
// @lc code=end