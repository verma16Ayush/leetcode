/*
@lc app=leetcode id=404 lang=cpp
 *
[404] Sum of Left Leaves
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
    int ans;
    void Help(TreeNode* root)
    {
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr) return;
        if(root->left && root->left->left == nullptr && root->left->right == nullptr) ans += root->left->val;
        Help(root->left);
        Help(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        Help(root);
        return ans;
    }
};
// @lc code=end

