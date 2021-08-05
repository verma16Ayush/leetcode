/*
@lc app=leetcode id=1019 lang=cpp
 *
[1019] Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        if(!head->next) return {0};
        vector<int> temp;
        for(head; head; head = head->next) temp.push_back(head->val);
        int n = temp.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--)
        {
            int t = temp[i];
            while(st.size() && t >= st.top()) st.pop();
            ans[i] = st.size() ? st.top() : 0;
            st.push(t);
        }
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ListNode* head = new ListNode(1,
                        new ListNode(7,
                            new ListNode(5,
                                new ListNode(1, 
                                    new ListNode(9,
                                        new ListNode(2,
                                            new ListNode(5,
                                                new ListNode(1
    ))))))));
    auto ans = Solution().nextLargerNodes(head);
    return 0;
}