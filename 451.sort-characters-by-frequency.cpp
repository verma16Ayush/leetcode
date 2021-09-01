/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        auto freq = vector<int>(128);
        for(char c : s) freq[c]++;
        sort(s.begin(), s.end(), [&](const char& a, const char& b)->bool{
            if(freq[a] != freq[b])
                return freq[a] > freq[b];
            return a > b;
        });
        return s;
    }
};
// @lc code=end

