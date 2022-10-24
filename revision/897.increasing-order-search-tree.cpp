/*
@lc app=leetcode id=897 lang=cpp
 *
[897] Increasing Order Search Tree
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
    // vector<int> temp;
    TreeNode* res;
    TreeNode* cur;
    void DFSHelper(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
            DFSHelper(root->left);
        res->right = new TreeNode(root->val);
        res = res->right;
        if(root->right)
            DFSHelper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        res = new TreeNode();
        cur = res;
        DFSHelper(root);
        return cur->right;
    }
};
// @lc code=end
TreeNode* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1)
        return nullptr;
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
    Solution().increasingBST(root);
    return 0;
}