/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int st = 0, en = a.size() - 1;
        while(st < en)
        {
            int s = a[st] + a[en];
            if(s == target) return {st + 1, en + 1};
            else if(s > target) en -= 1;
            else st += 1;
        }
        return {};
    }
};
// @lc code=end

