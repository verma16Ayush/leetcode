/*
@lc app=leetcode id=701 lang=cpp
 *
[701] Insert into a Binary Search Tree
 */

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
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void insert(TreeNode* root, int val)
    {
        if(!root)
        {
            root = new TreeNode(val);
            return;
        }
        else if(val > root->val)
        {
            if(root->right)
                insert(root->right, val);
            else
                root->right = new TreeNode(val);
        }
        else if(val < root->val)
        {
            if(root->left)
                insert(root->left, val);
            else
                root->left = new TreeNode(val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) 
            return new TreeNode(val);
        insert(root, val);
        return root;
    }
};
// @lc code=end

