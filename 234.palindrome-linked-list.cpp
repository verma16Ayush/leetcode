/*
@lc app=leetcode id=234 lang=cpp
 *
[234] Palindrome Linked List
 */

// @lc code=start

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        int i = 0;
        ListNode* cur = head;
        ListNode* fastp = head;
        ListNode* slowp = head;
        while(fastp && fastp->next)
        {
            i += 1;
            slowp = slowp->next;
            fastp = fastp->next->next;
        }

        if(fastp) slowp = slowp->next;
        stack<int> st;
        while(slowp)
        {
            st.push(slowp->val);
            slowp = slowp->next;
        }
        while(cur && !st.empty())
        {
            if(cur->val != st.top()) return false;
            cur = cur->next;
            st.pop();
        }
        return true;
    }
};
// @lc code=end

