/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct mp
{
    int _val;
    int _min;
    mp(int val, int min)
    {
        _val = val;
        _min = min;
    }
};
class MinStack {
private:
    stack<mp> _st;
public:
    /** initialize your data structure here. */
    MinStack() {
        // pass
    }
    
    void push(int val) 
    {
        if(_st.size() == 0)
        {
            _st.push(mp(val, val));
            return;
        }
        if(val < _st.top()._min)
        {
            _st.push(mp(val, val));
        }
        else _st.push(mp(val, _st.top()._min));
    }
    
    void pop() 
    {
        _st.pop();
    }
    
    int top() 
    {
        return _st.top()._val;
    }
    
    int getMin() {
        return _st.top()._min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     MinStack ms;
//     ms.push(-2);
//     ms.push(0);
//     ms.push(-3);
//     cout << ms.getMin() << endl;
//     ms.pop();
//     cout << ms.top() << endl;
//     cout << ms.getMin() << endl;
//     return 0;
// }

