/*
@lc app=leetcode id=160 lang=cpp
 *
[160] Intersection of Two Linked Lists
 */

/**
Definition for singly-linked list.
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        auto p1 = headA;
        while(p1)
        {
            st.insert(p1);
            p1 = p1->next;
        }
        auto p2 = headB;
        while(p2)
        {
            if(st.count(p2))
                return p2;
            p2 = p2->next;
        }
        return nullptr;
    }
};
// @lc code=end

