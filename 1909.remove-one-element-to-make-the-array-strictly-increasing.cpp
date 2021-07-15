/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool IsSorted(vector<int>& a, int s, int e)
    // {
    //     for(int i = s; i + 1 <= e; i++)
    //     {
    //         if(a[i + 1] <= a[i]) return false;
    //     }
    //     return true;
    // }
    // bool canBeIncreasing(vector<int>& nums) 
    // {
    //     if(nums.size() <= 2) return true;
    //     unordered_set<int> s;
    //     vector<int> nums2;
    //     nums2.push_back(-1);
    //     for(int i : nums) nums2.push_back(i);
    //     nums2.push_back(1002);

    //     int c = 0;
    //     for(int i : nums2)
    //     {
    //         if(s.find(i) != s.end()) c++;
    //         else s.insert(i);
    //     }
    //     if(c > 1) return false;
    //     for(int i = 1; i < nums2.size() - 1; i++)
    //     {
    //         if(IsSorted(nums2, 0, i - 1) && IsSorted(nums2, i + 1, nums2.size() - 1) && nums2[i - 1] < nums2[i + 1]) return true;
    //     }
    //     return false;
    // }

    bool canBeIncreasing(vector<int>& nums) 
    {
        vector<>
    }
};
// @lc code=end

