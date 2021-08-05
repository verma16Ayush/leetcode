/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() 
        : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) 
        : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
class Solution {
public:
    // Node* connect(Node* root) {
    //     if(!root) return root;
    //     queue<Node*> q;
    //     vector<Node*> temp;
    //     q.push(root);
    //     q.push(nullptr);

    //     while(q.size())
    //     {
    //         Node* front = q.front();
    //         q.pop();
    //         if(front == nullptr)
    //         {
    //             for(int i = 0; i < temp.size() - 1; i++)
    //             {
    //                 temp[i]->next = temp[i + 1];
    //             }
    //             temp = vector<Node*>();
    //             if(q.size() == 0)break;
    //             q.push(nullptr);
    //             continue;
    //         }
    //         temp.push_back(front);
    //         if(front->left) q.push(front->left);
    //         if(front->right) q.push(front->right);
    //     }
    //     return root;
    // }

    Node* getLeft(Node* root)
    {
        if(!root) return nullptr;
        if(root->left) return root->left;
        if(root->right) return root->right;
        else return nullptr;
    }
    void help(Node* root)
    {
        if(!root) return;
        Node* nxt = getLeft(root->l);
        if(root->left) root->next = nxt;
        help(root->left);
        help(root->right);
    }
    Node* connect(Node* root)
    {
        if(!root) return root;
        help(root);
        return root;
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
    Solution().connect(root);
    return 0;
}