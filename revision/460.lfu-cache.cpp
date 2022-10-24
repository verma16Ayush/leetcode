/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class LFUCache {
    int _cap;
    unordered_map<int, pair<int, int>> _keyFreqValCache;
    unordered_map<int, list<int>::iterator> _iterMap;
    map<int, list<int>> _freqKeyList;

public:
    LFUCache(int capacity) {
        this->_cap = capacity;
        this->_keyFreqValCache = unordered_map<int, pair<int, int>>();
        this->_iterMap = unordered_map<int, list<int>::iterator>();
        this->_freqKeyList = map<int, list<int>>();
    }
    
    int get(int key) {
        if(_keyFreqValCache.count(key) == 0)
            return -1;
        auto freqValPair = _keyFreqValCache[key];
        freqValPair.first++;
        auto keyListIter = _iterMap[key];
        _freqKeyList[freqValPair.first - 1].erase(keyListIter);
        if(_freqKeyList[freqValPair.first - 1].size() == 0)
                _freqKeyList.erase(freqValPair.first - 1);
        _freqKeyList[freqValPair.first].insert(_freqKeyList[freqValPair.first].begin(), key);
        _iterMap[key] = _freqKeyList[freqValPair.first].begin();
        _keyFreqValCache[key] = freqValPair;
        return freqValPair.second;
    }
    
    void put(int key, int value) {
        if(!_cap)
            return;
        if(_keyFreqValCache.count(key))
        {
            auto freqValPair = _keyFreqValCache[key];
            auto keyListIter = _iterMap[key];
            _freqKeyList[freqValPair.first].erase(keyListIter);
            if(_freqKeyList[freqValPair.first].size() == 0)
                _freqKeyList.erase(freqValPair.first);
            _keyFreqValCache[key] = {freqValPair.first + 1, value};
            _freqKeyList[freqValPair.first + 1].insert(_freqKeyList[freqValPair.first + 1].begin(), key);
            _iterMap[key] = _freqKeyList[freqValPair.first + 1].begin();
            return;
        }
        else
        {
            if(_keyFreqValCache.size() + 1 > _cap)
            {
                auto minFreqKeyListItem = _freqKeyList.begin();
                int minFreqKey = minFreqKeyListItem->second.back();
                minFreqKeyListItem->second.pop_back();
                _keyFreqValCache.erase(minFreqKey);
                _iterMap.erase(minFreqKey);
            }
            _keyFreqValCache[key] = {1, value};
            _freqKeyList[1].insert(_freqKeyList[1].begin(), key);
            _iterMap[key] = _freqKeyList[1].begin();
        }
    }

    void UpdateKey(int key)
    {
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
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
    LFUCache lfu = *new LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4); 
    return 0;
}