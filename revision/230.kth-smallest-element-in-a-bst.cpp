/*
@lc app=leetcode id=230 lang=cpp
 *
[230] Kth Smallest Element in a BST
 */
#include <bits/stdc++.h>
using namespace std;
/**
Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
class Solution {
public:
    vector<int> inorder;
    Solution() : inorder(vector<int>()) {}
    void DFSHelper(TreeNode* root) 
    {
        if(!root)
            return;
        if(root->left)
            DFSHelper(root->left);
        inorder.push_back(root->val);
        if(root->right)
            DFSHelper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        DFSHelper(root);
        if(inorder.size() < k)
            return -1;
        return inorder[k - 1];
    }
};
// @lc code=end

