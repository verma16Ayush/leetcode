/*
@lc app=leetcode id=23 lang=cpp
 *
[23] Merge k Sorted Lists
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.empty()) return nullptr;
        ListNode* merged = new ListNode();
        ListNode* mergecp = merged;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* l : lists)
        {
            if(l) pq.push(l);
        }

        while(pq.size())
        {
            ListNode* top = pq.top();
            pq.pop();
            merged->next = new ListNode(top->val);
            merged = merged->next;
            if(top->next) pq.push(top->next);
        }
        return mergecp->next;
    }
};
// @lc code=end

