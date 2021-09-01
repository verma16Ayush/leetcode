/*
@lc app=leetcode id=653 lang=cpp
 *
[653] Two Sum IV - Input is a BST
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
class Solution {
public:
    bool FindTarget(TreeNode* root, int k, TreeNode* donUse)
    {
        bool b = false;
        if(!root) return b;
        if(root->val == k && root != donUse) return true;
        else if(k > root->val) b = b || FindTarget(root->right, k, donUse);
        else b = b || FindTarget(root->left, k, donUse);
        return b;
    }
    
    bool Help(TreeNode* root, TreeNode* curRoot, int k)
    {
        if(!root || !curRoot) return false;
        if(FindTarget(root, k - curRoot->val, curRoot)) return true;
        return Help(root, curRoot->left, k) || Help(root, curRoot->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return Help(root, root, k);
    }
};
// @lc code=end

