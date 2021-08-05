/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            a[i] = to_string(nums[i]);
        }

        sort(a.begin(), a.end(), [&](const string& a, const string& b) -> bool{
            string s1 = a + b;
            string s2 = b + a;
            return s1 > s2;
        });

        string ans = "";
        for(string& i : a)
            ans.append(i);

        int c0 = 0;
        for(char c : ans) c0 += (c == '0');
        if(c0 == ans.size()) 
            return "0";
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
    vector<int> nums = {3,30,34,5,9};
    auto ans = Solution().largestNumber(nums);
    return 0;
}