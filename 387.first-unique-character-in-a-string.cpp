/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26);
        for(int i = 0; i < s.length(); i++){
            mp[s[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "leetcode";
    cout << Solution().firstUniqChar(s);
    return 0;
}

