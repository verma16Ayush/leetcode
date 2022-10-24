/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> st;
        for(int i= 0; i <= k && i < nums.size(); i++)
        {
            if(st.count(nums[i]))
                return true;
            else
                st.insert(nums[i]);
        }
        int en = k, str = 0;
        while(en < nums.size())
        {
            st.erase(nums[str]);
            en += 1;
            str += 1;
            if(en < nums.size())
            {
                if(st.count(nums[en]))
                    return true;
                else
                    st.insert(nums[en]);
            }
        }
        return false;
        
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}