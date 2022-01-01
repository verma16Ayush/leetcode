/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyQueue {
    stack<int> push_st;
    stack<int> pop_st;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        push_st = stack<int>();
        pop_st = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(pop_st.size())
        {
            int top = pop_st.top();
            pop_st.pop();
            return top;
        }
        else if(push_st.size())
        {
            while(push_st.size())
            {
                int top = push_st.top();
                pop_st.push(top);
                push_st.pop();
            }
            int top = pop_st.top();
            pop_st.pop();
            return top;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() {
        if(pop_st.size())
        {
            return pop_st.top();
        }
        else if(push_st.size())
        {
            while(push_st.size())
            {
                int top = push_st.top();
                pop_st.push(top);
                push_st.pop();
            }
            return pop_st.top();
        }
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(!push_st.size() && !pop_st.size())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

