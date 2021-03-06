/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

/**
 * Definition for singly-linked list.
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
};
// @lc code=end

