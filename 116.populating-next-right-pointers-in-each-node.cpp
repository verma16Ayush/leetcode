/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root) return nullptr;
        // queue<Node*> q;
        // // vector<vector<Node*>> ans;
        // vector<Node*> temp;
        // q.push(root);
        // q.push(nullptr);
        // while(!q.empty())
        // {
        //     auto front = q.front();
        //     q.pop();
        //     if(front == nullptr)
        //     {
        //         for(int i = 0; i < temp.size() - 1; i++) temp[i]->next = temp[i + 1];
        //         temp.clear();
        //         if(q.empty()) break;
        //         q.push(nullptr);
        //         continue;
        //     }
        //     temp.push_back(front);
        //     if(front->left) q.push(front->left);
        //     if(front->right) q.push(front->right);
        // }
        help(root);
        return root;
    }

    // optimise it away
    void help(Node* cur)
    {
        if(!(cur->left && cur->right)) return;
        cur->left->next = cur->right;
        cur->right->next = cur->next ? cur->next->left : nullptr;
        help(cur->left);
        help(cur->right);
    }
};
// @lc code=end

Node* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1) return nullptr;
    Node* root = new Node(t);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Node* root = BuildTree();
    Solution sol;
    sol.connect(root);
    return 0;
}