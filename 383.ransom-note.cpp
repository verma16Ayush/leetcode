/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mpr(26), mpm(26);
        for(char c : ransomNote)
            mpr[c - 'a']++;
        for(char c : magazine)
            mpm[c - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(mpm[i] < mpr[i])
                return 0;
        
        return 1;
    }
};
// @lc code=end

