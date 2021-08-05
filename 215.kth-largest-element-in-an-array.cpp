/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
#define M1
using namespace std;

#ifdef M1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i : nums)
        {
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
#endif

#ifdef M2
class Solution {
public:
    int part(vector<int>& a, int l, int r)
    {
        int i = l - 1;
        int pivot = r;
        for(int j = l; j < r; j++)
        {
            if(a[j] <= a[pivot])
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[pivot], a[i + 1]);
        return i + 1;
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        shuffle(nums.begin(), nums.end(), default_random_engine(time(0)));
        int fi = nums.size() - k;
        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int k = part(nums, l, r);
            if(k == fi) break;
            if(k < fi) l = k + 1;
            else r = k - 1;
        }
        return nums[fi];
    }
};
#endif
// @lc code=end
