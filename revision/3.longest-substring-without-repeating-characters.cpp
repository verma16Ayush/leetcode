/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int i = 0, j = 0;
        int mlen = 0;
        unordered_map<char, int> u_mp;
        while(j < s.length() && i <= j)
        {
            if(!u_mp[s[j]])
            {
                mlen = max(mlen, j - i + 1);
                u_mp[s[j]]++;
                j++;
            }
            else
            {
                u_mp[s[i]]--;
                i++;
            }
        }
        return mlen;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;

    return 0;
}