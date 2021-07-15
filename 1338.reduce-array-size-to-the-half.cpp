/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int  i : arr)
        {
            mp[i]++;
            // mp[i].first = i;
        }
        vector<pair<int, int>> vp;
        for(auto i : mp)
        {
            vp.push_back({i.first, i.second});
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        int k = 0;
        int rem = 0;
        for(auto i : vp)
        {
            if(rem >= arr.size() / 2) break;
            rem += i.second;
            k += 1;            
        }
        return k;
    }
};
// @lc code=end

