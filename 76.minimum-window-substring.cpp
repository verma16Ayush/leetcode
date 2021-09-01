/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for(char c : t) freq[c]++;
        int cnt = freq.size();
        
        int st = 0, en = 0;
        int minLen = INT32_MAX;
        int minst = 0;
        for(en; en < s.length(); en++)
        {
            if(freq.find(s[en]) != freq.end())
            {
                freq[s[en]]--;
                if(freq[s[en]] == 0) cnt--;
            }
            while(cnt == 0)
            {
                if(en - st + 1 < minLen)
                {
                    minLen = en - st + 1;
                    minst = st;
                }
                if(freq.find(s[st]) != freq.end()) 
                {
                    if(freq[s[st]] == 0) cnt++;
                    freq[s[st]]++;
                    st++;
                }
                else
                {
                    st++;
                    if(en - st + 1 < minLen)
                    {
                        minLen = en - st + 1;
                        minst = st;
                    }
                }
            }
        }
        return minLen > s.size() ? "" : s.substr(minst, minLen);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "a";
    string t = "a";
    cout << Solution().minWindow(s, t);
    return 0;
}