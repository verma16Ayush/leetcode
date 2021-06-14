/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* h = head;
        Node* c = new Node(0);
        Node* ans = c;
        unordered_map<Node*, Node*> mp;

        for(h; h != nullptr; h = h->next)
        {
            c->next = new Node(h->val);
            c = c->next;
            mp[h] = c;
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->first->random != nullptr) it->second->random = mp[it->first->random];
        }

        return ans->next;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    Node* head1 = new Node(1);
    Node* head2 = new Node(2);
    Node* head3 = new Node(3);
    Node* head4 = new Node(4);
    Node* head5 = new Node(5);

    head1->next = head2, head2->next = head3, head3->next = head4, head4->next = head5;
    head1->random = nullptr;
    head2->random = head1;
    head3->random = head4;
    head5->random = head5;

    Solution sol;
    Node* newList = sol.copyRandomList(head1);

    return 0;
}