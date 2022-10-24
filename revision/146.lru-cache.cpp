/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// struct Node{
//     int key, val;
//     Node() : key(0), val(0) {}
//     Node(int _key, int _val) : key(_key), val(_val) {}
// };

class LRUCache {
public:
    list<pair<int, int>> _dll;
    unordered_map<int, list<pair<int, int>>::iterator> _mp;
    int _cap;
    LRUCache(int capacity) {
        this->_cap = capacity;
        this->_dll = list<pair<int, int>>();
        this->_mp = unordered_map<int, list<pair<int, int>>::iterator>();
    }
    
    int get(int key) {
        if(_mp.find(key) == _mp.end())
            return -1;
        int retkey = (*_mp[key]).second;
        _dll.splice(_dll.begin(), _dll, _mp[key]);
        return retkey;
    }
    
    void put(int key, int value) {
        if(_mp.find(key) != _mp.end())
        {
            (*_mp[key]).second = value;
            _dll.splice(_dll.begin(), _dll, _mp[key]);
            return;
        }
        if(_mp.size() + 1 > _cap)
        {
            int delkey = _dll.back().first;
            _mp.erase(delkey);
            _dll.pop_back();
        }
        _dll.insert(_dll.begin(), {key, value});
        _mp[key] = _dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    LRUCache* lRUCache = new LRUCache(2);
    // lRUCache->put(1, 1); // cache is {1=1}
    // lRUCache->put(2, 2); // cache is {1=1, 2=2}
    // lRUCache->get(1);    // return 1
    // lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lRUCache->get(2);    // returns -1 (not found)
    // lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lRUCache->get(1);    // return -1 (not found)
    // lRUCache->get(3);    // return 3
    // lRUCache->get(4);    // return 4
    lRUCache->get(2);
    lRUCache->put(2, 6);
    lRUCache->get(1);
    lRUCache->put(1, 5);
    lRUCache->put(1, 2);
    lRUCache->get(1);
    lRUCache->get(2);
    return 0;
}