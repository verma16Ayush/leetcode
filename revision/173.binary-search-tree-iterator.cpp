/*
@lc app=leetcode id=173 lang=cpp
 *
[173] Binary Search Tree Iterator
 */

/**
Definition for a binary tree node.
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
class BSTIterator {
public:
    // vector<int> inorder;
    // int it;
    stack<TreeNode*> st;
    // void DFSHelper(TreeNode* root)
    // {
    //     if(!root)
    //         return;
    //     if(root->left)
    //         DFSHelper(root->left);
    //     inorder.push_back(root->val);
    //     if(root->right)
    //         DFSHelper(root->right);
    // }
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur)
        {
            st.push(cur);
            cur = cur->left;
        }
    }
    
    int next() {
        // if(st.size())
        TreeNode* node = st.top();
        st.pop();
        TreeNode* cur = node->right;
        while(cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        return node->val;
    }
    
    bool hasNext() {
        return st.size();
    }
};

/**
Your BSTIterator object will be instantiated and called as such:
BSTIterator* obj = new BSTIterator(root);
int param_1 = obj->next();
bool param_2 = obj->hasNext();
 */
// @lc code=end

