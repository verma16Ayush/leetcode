/*
@lc app=leetcode id=145 lang=cpp
 *
[145] Binary Tree Postorder Traversal
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
        Help(root->left);
        Help(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        ans = vector<int>();
        Help(root);
        return ans;
    }
};
// @lc code=end

