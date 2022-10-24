/*
@lc app=leetcode id=669 lang=cpp
 *
[669] Trim a Binary Search Tree
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
    vector<TreeNode*> temp;

    TreeNode* FindLow(TreeNode* root, int low)
    {
        if(!root)
            return nullptr;
        if(root->val < low)
            return root;
        return FindLow(root->left, low);
    }
    TreeNode* FindHi(TreeNode* root, int hi)
    {
        if(!root)
            return nullptr;
        if(root->val > hi)
            return root;
        return FindHi(root->right, hi);
    }

    TreeNode* Trim(TreeNode* root, TreeNode* lo, TreeNode* hi)
    {
        
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* lo = FindLow(root, low);
        TreeNode* hi = FindHi(root, high);

    }
};
// @lc code=end

