/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0, en = numbers.size() - 1;

        int sum = numbers[st] + numbers[en];
        while(st < en)
        {
            sum = numbers[st] + numbers[en];
            if(sum < target)
                st++;
            else if(sum > target)
                en--;
            else
                break;
        }
        return {st + 1, en + 1};
    }
};
// @lc code=end
