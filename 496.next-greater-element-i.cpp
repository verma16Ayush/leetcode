/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() == 1) return {-1};
        if(nums2.empty()) return {};
        vector<int> st;
        vector<int> ans(nums2.size());
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--)
        {
            int t = nums2[i];
            while(st.size() && st.back() <= t) st.pop_back();
            ans[i] = st.size() ? st.back() : -1;
            st.push_back(t);
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[nums2[i]] = ans[i];
        ans.clear();
        for(auto i : nums1) ans.push_back(mp[i]);
        return ans;
    }
};
// @lc code=end

