/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

struct cmp{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
    }
};

class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> mp;
    //     for(int& i : nums)
    //         mp[i]++;
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;
    //     for(auto& p : mp)
    //     {
    //         pq.push(p);
    //         if(pq.size() > k)
    //             pq.pop();
    //     }
    //     vector<int> ans;
    //     while(pq.size())
    //     {
    //         ans.push_back(pq.top().first);
    //         pq.pop();
    //     }
    //     return ans;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        for(int& i : nums)
            mp[i]++;
        vector<vector<int>> a (nums.size() + 1);
        for(auto i : mp)
            a[i.second].push_back(i.first);
        
        vector<int> ans;
        int i = a.size() - 1;
        while(i >= 0 && ans.size() != k)
        {
            if(a[i].size())
            {
                for(int j = 0; j < a[i].size() && ans.size() != k; j++)
                {
                    ans.push_back(a[i][j]);
                }
            }
            i--;
        }
        return ans;
    }
};
// @lc code=end

