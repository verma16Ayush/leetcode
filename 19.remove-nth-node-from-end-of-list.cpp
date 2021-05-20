/*
@lc app=leetcode id=19 lang=cpp
 *
[19] Remove Nth Node From End of List
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head->next == nullptr)
        {
            delete head;
            return nullptr;
        }
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* end = newHead;
        ListNode* del = newHead;
        for(int i = 0; i < n; i++)
        {
            end = end->next;
        }
        while(end->next)
        {
            end = end->next;
            del = del->next;
        }
        ListNode* temp = del->next;
        del->next = del->next->next;
        delete temp;
        return newHead->next;
    }
};


// @lc code=end

