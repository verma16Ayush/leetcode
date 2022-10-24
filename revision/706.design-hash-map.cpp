/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyHashMap {
public:
    vector<int> map;
    MyHashMap() {
        map = vector<int>(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

