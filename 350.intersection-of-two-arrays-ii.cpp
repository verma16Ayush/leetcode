/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp1, mp2;
        for(int i : nums1) mp1[i]++;
        for(int i : nums2) mp2[i]++;
        
        for(auto i : mp1)
        {
            if(mp2.find(i.first) != mp2.end())
            {
                int k = min(mp2[i.first], i.second);
                for(int j = 0; j < k; j++)
                {
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// #include <bits/stdc++.h>
// using namespace std;