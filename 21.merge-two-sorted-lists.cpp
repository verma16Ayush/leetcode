/*
@lc app=leetcode id=21 lang=cpp
 *
[21] Merge Two Sorted Lists
 */

/**
Definition for singly-linked list.
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
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5, new ListNode(9))));
    ListNode* b = new ListNode(1);
    ListNode* res = Solution().mergeTwoLists(a, b);
    return 0;
}