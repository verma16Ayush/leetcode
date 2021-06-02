/*
@lc app=leetcode id=146 lang=cpp
 *
[146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    int _cap;
    unordered_map<int, list< pair<int, int> >::iterator > _mp;
    list<pair<int,int> > _dl;
public:
    LRUCache(int capacity) 
    {
        this->_cap = capacity;
        this->_dl = list< pair<int, int> >();
        this->_mp = unordered_map< int, list< pair<int, int> >::iterator > ();
    }
    
    int get(int key) 
    {
        if(_mp.find(key) == _mp.end()) return -1;
        
        _dl.splice(_dl.begin(), _dl, _mp[key]);
        return _mp[key]->second;
    }
    
    void put(int key, int value) 
    {
        if(_mp.find(key) == _mp.end())         
        {
            if(_mp.size() + 1 > _cap) 
            {
                int _del_key = _dl.back().first;
                _mp.erase(_del_key);
                _dl.pop_back();
            }
            _dl.push_front({key, value});
            _mp[key] = _dl.begin();
        }
        else
        {
            _dl.splice(_dl.begin(), _dl, _mp[key]);
            _mp[key]->second = value;
        }
    }
};



// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1); // cache is {1=1}
    obj->put(2, 2); // cache is {1=1, 2=2}
    cout << obj->get(1) << endl;    // return 1
    obj->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << obj->get(2) << endl;    // returns -1 (not found)
    obj->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << obj->get(1) << endl;    // return -1 (not found)
    cout << obj->get(3) << endl;    // return 3
    cout << obj->get(4) << endl;    // return 4
    return 0;
}

