/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyCalendar {
public:
    vector<pair<int, int>> slots;
    MyCalendar() {
        slots = vector<pair<int, int> > ();
    }
    
    bool book(int start, int end) {
        for(pair<int, int> slot : slots)
            if(max(slot.first, start) < min(slot.second, end))
                return false;
        slots.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

