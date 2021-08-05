/*
@lc app=leetcode id=148 lang=cpp
 *
[148] Sort List
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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;
        auto h2 = new ListNode();
        h2->next = head;
        ListNode* fast = h2;
        ListNode* slow = h2;
        ListNode* pre = nullptr;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* mergedList = new ListNode();
        auto mcp = mergedList;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 && cur2)
        {
            if(cur1->val <= cur2->val)
            {
                mcp->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                mcp->next = cur2;
                cur2 = cur2->next;
            }
            mcp = mcp->next;
        }
        if(cur1) mcp->next = cur1;
        else if(cur2) mcp->next = cur2;
        return mergedList->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* mid = middleNode(head);
        ListNode* l2 = sortList(mid->next);
        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        
        return mergeTwoLists(l1, l2);
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

