/*
@lc app=leetcode id=160 lang=cpp
 *
[160] Intersection of Two Linked Lists
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x, ListNode* next = nullptr) {
//         val = x;
//         this->next = next;
//     }
// };

class Solution {
public:
    int CountNodes(ListNode* head)
    {
        int c = 0;
        ListNode* cur = head;
        for(cur; cur != nullptr; cur = cur->next) c++;
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(!headA || !headB) return 0;
        int m = CountNodes(headA);
        int n = CountNodes(headB);
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(m != n)
        {
            m < n ? curB = curB->next : curA = curA->next;
            m < n ? n-- : m--;
        }

        while(curA != curB && curA != NULL && curB != NULL)
        {
            curA = curA->next;
            curB = curB->next;
        }
        return curA == curB ? curA : NULL; 
    }
};
// @lc code=end

// ListNode* BuildList()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int& i : a) cin >> i;
//     ListNode* l = new ListNode(0);
//     ListNode* copy = l;
//     for(int i : a)
//     {
//         l->next = new ListNode(i);
//         l = l->next;
//     }
//     copy = copy->next;
//     return copy;
// }

// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     ListNode* l1 = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));
//     ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(1, l1->next->next)));
//     Solution sol;
//     cout << sol.getIntersectionNode(l1, l2)->val << endl;
//     return 0;
// }
