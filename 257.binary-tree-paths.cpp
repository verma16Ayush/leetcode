/*
@lc app=leetcode id=257 lang=cpp
 *
[257] Binary Tree Paths
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
    vector<string> ans;
    void Help(TreeNode* root, string temp)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            temp = temp + (to_string(root->val));
            ans.push_back(temp);
        }
        temp = temp + to_string(root->val) + "->";
        if(root->left) Help(root->left, temp);
        if(root->right) Help(root->right, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        Help(root, string());
        return ans;
    }
};
// @lc code=end

