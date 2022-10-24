/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int st = 0, en = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        mp[1] = 0;

        int maxLen = 0;

        while(en < nums.size() && st <= en)
        {
            mp[nums[en]]++;
            while(mp[0] > 1)
            {
                mp[nums[st]]--;
                st++;
            }
            maxLen = max(maxLen, en - st);
            en++;
        }
        return maxLen;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector<int> a = {0,1,1,1,0,1,1,0,1};
    cout << Solution().longestSubarray(a) << endl;
    return 0;
}