/*
@lc app=leetcode id=142 lang=cpp
 *
[142] Linked List Cycle II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head) return nullptr;
        ListNode* fastp = head;
        ListNode* slowp = head;
        int flag = 0;

        while(true)
        {
            if(!fastp->next || !fastp->next->next) return nullptr;
            fastp = fastp->next->next;
            slowp = slowp->next;
            if(fastp == slowp)
            {
                flag = 1;
                break;
            }
        }
        slowp = head;
        while(fastp != slowp)
        {
            fastp = fastp->next;
            slowp = slowp->next;
        }
        return fastp;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ListNode* head = new ListNode(1, new ListNode(2, nullptr));
    Solution sol;
    cout << sol.detectCycle(head) << endl;
    return 0;
}
