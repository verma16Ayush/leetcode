/*
@lc app=leetcode id=83 lang=cpp
 *
[83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* i = head;
        ListNode* j = head->next;
        for(i, j; j != nullptr;)
        {
            if(i->val == j->val)
            {
                j = j->next;
                continue;
            }
            else
            {
                i->next = j;
                i = i->next;
                j = j->next;
            }
        }
        i->next = nullptr;
        return head;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4))))));
    Solution().deleteDuplicates(head);
    return 0;
}

