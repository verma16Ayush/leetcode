/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& a) 
    {
        unordered_set<int> keys;
        for(int i = 0; i < a.size(); i++)
        {
            if(keys.find(a[i]) != keys.end()) return true;
            else keys.insert(a[i]);
        }
        return false;
    }
};
// @lc code=end

