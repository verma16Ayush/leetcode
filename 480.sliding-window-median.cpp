/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
typedef long long ll;
typedef long double ld;

struct cmp{
    bool operator()(const int* a, const int* b) const
    {
        return *a < *b;
    }
};

class Solution {
public:
    // maxheap to store the first half. will contain 1 extra element if needed.
    multiset<int*, cmp> maxheap;
    // minheap to store the second half. will contain 
    // 1 less element than maxheap if needed
    multiset<int*, cmp> minheap;

    Solution() : maxheap(multiset<int*, cmp>()), minheap(multiset<int*, cmp>()) {}

    void Insert(int* ptr)
    {
        if(maxheap.empty() && minheap.empty())
            maxheap.insert(ptr);
        else if(maxheap.empty())
        {
            if(*ptr > **minheap.begin())
                minheap.insert(ptr);
            else
                maxheap.insert(ptr);
        }
        else
        {
            if(*ptr <= **maxheap.rbegin())
                maxheap.insert(ptr);
            else
                minheap.insert(ptr);
        }

        Balance();
    }

    void Delete(int* ptr)
    {
        auto it = minheap.find(ptr);
        if(it != minheap.end())
        {
            minheap.erase(it);
        }
        else 
        {
            it = maxheap.find(ptr);
            maxheap.erase(it);
        }
        Balance();
    }

    void Balance()
    {
        if(minheap.size() == maxheap.size() || minheap.size() + 1 == maxheap.size())
            return;
        else if(minheap.size() > maxheap.size())
        {
            int* top = *minheap.begin();
            minheap.erase(minheap.begin());
            maxheap.insert(top);
            return;
        }
        else
        {
            int* top = *maxheap.rbegin();
            auto it = --maxheap.end();
            maxheap.erase(it);
            minheap.insert(top);
            return;
        }
    }

    double Median()
    {
        if(minheap.size() == maxheap.size())
            return ((ll)**minheap.begin() + (ll)**maxheap.rbegin()) / 2.0;
        else
            return (double)**maxheap.rbegin();
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        for(int i = 0; i < k; i++)
        {
            Insert(&nums[i]);
        }
        int st = 0, en = k - 1;
        for(st, en; en < nums.size() - 1;)
        {
            ans.push_back(Median());
            Delete(&nums[st++]);
            Insert(&nums[++en]);
        }
        ans.push_back(Median());
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // vector<int> a = {2147483647,2147483647};
    // vector<int> a = {7,0,3,9,9,9,1,7,2,3};
    vector<int> a = {4,1,7,1,8,7,8,7,7,4};
    auto ans = Solution().medianSlidingWindow(a, 4);
    return 0;
}