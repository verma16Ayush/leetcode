/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

