/*
@lc app=leetcode id=23 lang=cpp
 *
[23] Merge k Sorted Lists
 */

/**
Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

struct NodeComp 
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, NodeComp > pq;
        for (auto list : lists)
            if(list)
                pq.push(list);
        ListNode* merged = new ListNode();
        ListNode* mcp = merged;
        while(pq.size())
        {
            ListNode* top = pq.top();
            pq.pop();
            merged->next = new ListNode(top->val);
            merged = merged->next;
            if(top->next)
                pq.push(top->next);
        }
        return mcp->next;
    }
};
// @lc code=end

