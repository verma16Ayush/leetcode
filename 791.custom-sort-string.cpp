/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string customSortString(string order, string str) {
        unordered_set<char> ord;
        for(char i : order) ord.insert(i);
        unordered_map<char, int> inorder;
        string rest, ans;
        
        for(int i : str) {
            if(ord.find(i) != ord.end()) inorder[i]++;
            else rest += i;
        }
        for(char c : order) {
            int i = 0;
            while(i < inorder[c]) {
                ans += c;
                i++;
            }
        }
        for(char c : rest) ans += c;
        return ans;
        // string('c', )
    }
};
// @lc code=end

