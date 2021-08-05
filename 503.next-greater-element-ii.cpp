/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size() == 1) return {-1};
        int n = nums.size();
        for(int i = 0; i < n; i++) nums.push_back(nums[i]);
        vector<int> st;
        vector<int> ans(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int t = nums[i];
            while(st.size() && t >= st.back()) st.pop_back();
            ans[i] = st.size() ? st.back() : -1;
            st.push_back(t);
        }
        ans.resize(n);
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
    vector<int> a = {1,2,1};
    auto ans = Solution().nextGreaterElements(a);
    return 0;
}
