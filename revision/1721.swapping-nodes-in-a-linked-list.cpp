/*
@lc app=leetcode id=1721 lang=cpp
 *
[1721] Swapping Nodes in a Linked List
 */

/**
Definition for singly-linked list.
 */
#include <bits/stdc++.h>
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* curr = head;
        
        int counter = 1;
        while(curr!=NULL){
            if (counter<k){
                left = left->next;
            }
            if (counter>k){
                right = right->next;
            }
            curr = curr->next;
            counter++;
        }
        //swap values
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        
        return head;
    }
};
// @lc code=end

