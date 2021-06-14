/*
@lc app=leetcode id=437 lang=cpp
 *
[437] Path Sum III
 */

// @lc code=start
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
class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int target)
    {
        if(!root) return;
        if(root->val == target) ans++;
        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);
    }

    void PathHelp(TreeNode* root, int target)
    {
        dfs(root, target);
        if(root->left) PathHelp(root->left, target);
        if(root->right) PathHelp(root->right, target);
    }

    int pathSum(TreeNode* root, int targetSum) 
    {
        ans = 0;
        if(root) PathHelp(root, targetSum);
        return ans;
    }
};
// @lc code=end

