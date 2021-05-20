/*
@lc app=leetcode id=143 lang=cpp
 *
[143] Reorder List
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution 
{
public:
    ListNode* ReOrder(ListNode* head, ListNode* secondLast)
    {
        if(head == secondLast)
        {
            return nullptr;
        }
        ListNode* temp = head->next;
        head->next = secondLast->next;
        secondLast->next->next = temp;
        secondLast->next = nullptr;
        return temp;
    }
    void reorderList(ListNode* head) 
    {
        ListNode* hcp = head;
        while(hcp)
        {
            ListNode* cur = hcp;
            while(cur->next && cur->next->next)
            {
                cur = cur->next;
            }
            hcp = ReOrder(hcp, cur);
        }
    }

};
// @lc code=end

