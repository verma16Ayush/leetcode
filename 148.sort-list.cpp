/*
@lc app=leetcode id=148 lang=cpp
 *
[148] Sort List
 */

// @lc code=start
#include <bits/stdc++.h>
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
    ListNode* Merge(ListNode* head1, ListNode* head2)
    {
        auto cur1 = head1;
        auto cur2 = head2;

        auto newNode = new ListNode();
        auto cp = newNode;

        while(cur1 != nullptr && cur2 != nullptr)
        {
            newNode->next = cur1->val < cur2->val ? cur1 : cur2;
            cur1->val < cur2->val ? cur1 = cur1->next : cur2 = cur2->next;
            newNode = newNode->next;
        }

        while(cur1 != nullptr)
        {
            newNode->next = cur1;
            cur1 = cur1->next;
            newNode = newNode->next;
        }

        while(cur2 != nullptr)
        {
            newNode->next = cur2;
            cur2 = cur2->next;
            newNode = newNode->next;
        }

        return cp->next; 
    }
    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return head;

        // Find middle
        auto fast = head, slow = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list2 = slow->next;
        slow->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(list2);
        
        return Merge(l1, l2);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    Solution sol;
    ListNode* sorted = sol.sortList(head);
    return 0;
}

