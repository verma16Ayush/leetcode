/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode();
        ListNode* r = res;
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            res->next = newNode;
            res = res->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return r->next;
    }
};
// @lc code=end

