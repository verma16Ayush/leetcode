/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct comp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, comp > q;
        // for(int i : arr)
        // {
        //     q.push({i, abs(x - i)});
        //     if(q.size() > k) q.pop();
        // }
        // vector<int> ans;
        // while(q.size())
        // {
        //     ans.push_back(q.top().first);
        //     q.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        vector<int> ans;
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int j = i + 1;
        while(ans.size() != k && i >= 0 && j < arr.size())
        {
            if(abs(x - arr[i]) < abs(x - arr[j])) ans.push_back(arr[i--]);
            else ans.push_back(arr[j++]);
        }
        if(i >= 0 && ans.size() != k)
        {
            while(ans.size() != k)
                ans.push_back(arr[i--]);
        }
        else if(j < arr.size() && ans.size() != k)
        {
            while(ans.size() != k)
                ans.push_back(arr[j++]);
        }
        sort(ans.begin(), ans.end());
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
    Solution sol;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> ans = sol.findClosestElements(a, 4, 3);
    return 0;
}

