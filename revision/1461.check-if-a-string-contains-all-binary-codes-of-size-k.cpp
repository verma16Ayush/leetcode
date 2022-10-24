/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int getNum(string s)
    {
        reverse(s.begin(), s.end());
        int k = 0;
        for(int i = 0; i < s.size(); i++)
        {
            k += (s[i] - '0') * (1 << i);
        }
        return k;
    }
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false;
        unordered_set<string> mp;
        
        for(int i = 0; i <= s.size() - k; i++)
        {
            mp.insert(s.substr(i, k));
        }
        
        return mp.size() == (1 << k);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "00110";
    cout << Solution().hasAllCodes(s, 2);
    return 0;
}