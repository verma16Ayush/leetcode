/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        if(a.empty()) return {};

        vector<pair<int, int>> test;
        vector<int> ans(a.size());
        for(int i = 0; i < a.size(); i++)
            test.push_back({a[i], i});
        
        stack<pair<int, int>> st;
        st.push(test[0]);
        for(int i = 1; i < a.size(); i++)
        {
            if(test[i].first <= st.top().first) st.push(test[i]);
            else
            {
                while(st.size() && st.top().first < test[i].first)
                {
                    ans[st.top().second] = test[i].second - st.top().second;
                    st.pop();
                }
                st.push(test[i]);
            }
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
    
    vector<int> a = {73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int> ans = sol.dailyTemperatures(a);
    for(int& i : ans) cout << i << " ";
    return 0;
}