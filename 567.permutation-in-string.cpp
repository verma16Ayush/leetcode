/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
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
    bool checkInclusion(string s1, string s2) {
        // unordered_set<char> st(s1.begin(), s1.end());
        // sort(s1.begin(), s1.end());
        // for(int i = 0; i < s2.size(); i++)
        // {
        //     if(st.find(s2[i]) != st.end())
        //     {
        //         if(i + s1.size() - 1 < s2.size())
        //         {
        //             string sub = s2.substr(i, s1.size());
        //             sort(sub.begin(), sub.end());
        //             if(sub == s1)
        //                 return 1;
        //         }
        //     }
        // }
        // return false;
        // minWindow(s1, s2).size() == s1.size() ? 1 : 0;
        string s = minWindow(s2, s1);
        return s.size() == s1.size() ? 1 : 0;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "ab";
    string s2 = "eidbaooo";
    cout << Solution().checkInclusion(s, s2);
    return 0;
}