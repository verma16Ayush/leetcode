/*
@lc app=leetcode id=21 lang=cpp
 *
[21] Merge Two Sorted Lists
 */

// @lc code=start
/**
Definition for singly-linked list.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    // {
    //     ListNode* sorted = new ListNode();
    //     ListNode* res = sorted;
    //     while(l1 && l2)
    //     {
    //         ListNode* newNode = new ListNode();
    //         if(l1->val < l2->val)
    //         {
    //             newNode->val = l1->val;
    //             l1 = l1->next;
    //         }
    //         else
    //         {
    //             newNode->val = l2->val;
    //             l2 = l2->next;
    //         }
    //         sorted->next = newNode;
    //         sorted = sorted->next;
    //     }
    //     while(l1 || l2)
    //     {
    //         ListNode* newNode = new ListNode(l1 ? l1->val : l2->val);
    //         l1 = l1 ? l1->next : nullptr;
    //         l2 = l2 ? l2->next : nullptr;
    //         sorted->next = newNode;
    //         sorted = sorted->next;
    //     }
    //     return res->next;
    // }
    ListNode* newNode = new ListNode();
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        
    }
};
// @lc code=end

