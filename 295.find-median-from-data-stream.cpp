/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MedianFinder {
public:
    // first half. will contain 1 extra element if needed
    priority_queue<int, vector<int>, less_equal<int> > maxheap;

    // second half. will contain 1 less in case of odd number of element;
    priority_queue<int, vector<int>, greater<int> > minheap;
    
    MedianFinder() : 
        maxheap(priority_queue<int, vector<int>, less_equal<int> >()), 
        minheap(priority_queue<int, vector<int>, greater<int> >()) 
        {}
    
    void addNum(int num) {
        if(minheap.empty() && maxheap.empty())
            maxheap.push(num);
        else if(maxheap.empty())
        {
            if(num > minheap.top())
                minheap.push(num);
            else
                maxheap.push(num);
        }
        else
        {
            if(num <= maxheap.top())
                maxheap.push(num);
            else 
                minheap.push(num);
        }
        
        if(maxheap.size() == minheap.size() || maxheap.size() == minheap.size() + 1)
            return;
        if(minheap.size() > maxheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
            return;
        }
        
        minheap.push(maxheap.top());
        maxheap.pop();
        return;
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size())
            return (minheap.top() + maxheap.top()) / 2.0;
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(2);
    pq.push(1);
    pq.push(4);
    cout << pq.top();
    pq.pop();
    cout << pq.top();
    return 0;
}