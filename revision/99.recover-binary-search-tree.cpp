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
    vector<TreeNode*> inorder;
    void DFSHelper(TreeNode* root)
    {
        if(root == nullptr)
            return;
        if(root->left)
            DFSHelper(root->left);
        inorder.push_back(root);
        if(root->right)
            DFSHelper(root->right);
    }
    void recoverTree(TreeNode* root) {
        DFSHelper(root);
        vector<int> swaps;
        int i = 0, j = inorder.size() - 1;
        while(i < inorder.size() - 1)
        {
            if(inorder[i]->val > inorder[i + 1]->val)
                break;
            i++;
        }

        while(j > 0)
        {
            if(inorder[j]->val < inorder[j - 1]->val)
                break;
            j--;
        }
        int c = inorder[i]->val;
        inorder[i]->val = inorder[j]->val;
        inorder[j]->val = c;
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
    Solution().recoverTree(root);
    return 0;
}