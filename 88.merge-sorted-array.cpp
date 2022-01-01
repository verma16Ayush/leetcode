/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start


class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> merged(m + n);
        int i = 0, j = 0;
        int k = 0;
        while(i < m && j < n)
        {
            if(a[i] < b[j])
            {
                merged[k++] = a[i++];
            }
            else
                merged[k++] = b[j++];
        } 

        while(i < m)
        {
            merged[k++] = a[i++];
        }

        while (j < n)
        {
            merged[k++] = b[j++];
        }
        a = merged;
    }
};
// @lc code=end

