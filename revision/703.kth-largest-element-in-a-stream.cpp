/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class KthLargest {
public:
    int k = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i : nums)
        {
            pq.push(i);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {4, 5, 8, 2};
    int k = 3;
    auto obj = KthLargest(3, a);
    cout << obj.add(3) << endl;
    cout << obj.add(5) << endl;
    cout << obj.add(10) << endl;
    cout << obj.add(9) << endl;
    cout << obj.add(4) << endl;
    return 0;
}
