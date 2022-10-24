/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyHashSet {
public:
    vector<bool> hashtable;
    MyHashSet() {
        hashtable = vector<bool>(1e6 + 1);
    }
    
    void add(int key) {
        hashtable[key] = 1;
    }
    
    void remove(int key) {
        hashtable[key] = 0;
    }
    
    bool contains(int key) {
        return hashtable[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

