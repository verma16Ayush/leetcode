/*
@lc app=leetcode id=144 lang=cpp
 *
[144] Binary Tree Preorder Traversal
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
    vector<int> ans;
    void Help(TreeNode* root)
    {
        if(!root) return;
        ans.push_back(root->val);
        Help(root->left);
        Help(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        Help(root);
        return ans;
    }
};
// @lc code=end

