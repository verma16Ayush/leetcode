/*
@lc app=leetcode id=203 lang=cpp
 *
[203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = new ListNode(-1, head);
        ListNode* cur = newHead;
        while(cur && cur->next)
        {
            if(cur->next->val == val)
            {
                auto temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                continue;
            }
            cur = cur->next;
        }
        return newHead->next;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto l = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7)))))));
    auto n = Solution().removeElements(l, 7);
    return 0;
}