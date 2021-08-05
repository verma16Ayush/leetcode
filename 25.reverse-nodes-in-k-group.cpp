/*
@lc app=leetcode id=25 lang=cpp
 *
[25] Reverse Nodes in k-Group
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* cur = nullptr;
        while(head)
        {
            ListNode* next = head->next;
            head->next = cur;
            cur = head;
            head = next;
        }
        return cur;   
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int c = 0;
        ListNode* cur = head;
        while(cur)
        {
            ListNode*& href = head; 

        }
    }
};
// @lc code=end

