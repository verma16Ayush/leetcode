/*
@lc app=leetcode id=23 lang=cpp
 *
[23] Merge k Sorted Lists
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* res = new ListNode();
        ListNode* cp = res;
        ListNode* min = lists[0];
        int mini = 0;
        while(lists[mini])
        {
            int i = 0;
            for(i; i < lists.size(); i++)
            {
                if(lists[i] == nullptr) continue;
                if(lists[i]->val < lists[mini]->val) mini = i;
            }
            res->next = new ListNode(lists[mini]->val);
            res = res->next;
            lists[mini] = lists[mini] ? lists[mini]->next : nullptr;
        }
        return cp->next;
    }
};
// @lc code=end

