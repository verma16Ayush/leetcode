/*
@lc app=leetcode id=24 lang=cpp
 *
[24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
         if ((head == nullptr)||(head->next == nullptr))
            return head;
        ListNode* n = head->next;
        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }
};
// @lc code=end

void PrintList(ListNode* head)
{
    auto cur = head;
    while(cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ListNode* one = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode* two = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* thr = new ListNode(1, new ListNode(2));
    ListNode* fou = new ListNode(1);

    Solution sol;
    one = sol.swapPairs(one);
    two = sol.swapPairs(two);
    thr = sol.swapPairs(thr);
    fou = sol.swapPairs(fou);
    PrintList(one);
    PrintList(two);
    PrintList(thr);
    PrintList(fou);
    return 0;
}