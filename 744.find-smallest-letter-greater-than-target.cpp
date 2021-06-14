/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int i = 0;
        while(i < letters.size() && letters[i] <= target) i++;
        return letters[i % letters.size()];        
    }
};
// @lc code=end

