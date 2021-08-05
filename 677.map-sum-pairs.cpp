/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MapSum {
private:
    unordered_map<string, int> mp;
    unordered_set<string> keys;
public:
    /** Initialize your data structure here. */
    MapSum() : mp(unordered_map<string, int>()), keys(unordered_set<string>()) {}
    
    void insert(string key, int val) {
        mp[key] = val;
        keys.insert(key);
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto it : keys)
        {
            if(it.find(prefix) == 0) ans += mp[it];
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

