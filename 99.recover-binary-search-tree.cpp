/*
@lc app=leetcode id=99 lang=cpp
 *
[99] Recover Binary Search Tree
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
    void Inorder(TreeNode* root)
    {
        if(!root) return;
        Inorder(root->left);
        temp.push_back(root);
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        Inorder(root);
        TreeNode* one, *two;
        for(int i = 0; i < temp.size() - 1; i++)
            if(temp[i]->val > temp[
                
            ])
        return;
    }
};
// @lc code=end

TreeNode* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1) return nullptr;
    TreeNode* root = new TreeNode(t);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    TreeNode* root = BuildTree();
    Solution sol;
    sol.recoverTree(root);
    return 0;
}