/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
#include<bits/stdc++.h>
using namespace std;

// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* k = head;
        ListNode* p = head;
        while(k && p && p->next)
        {
            k = k->next;
            p = p->next->next;
            if(k == p) return true;
        }
        return false;
    }
};
// @lc code=end

