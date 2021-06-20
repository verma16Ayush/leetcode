/*
@lc app=leetcode id=114 lang=cpp
 *
[114] Flatten Binary Tree to Linked List
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
    TreeNode* prev;
    void Help(TreeNode* root)
    {
        if(!root) return;
        Help(root->right);
        Help(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    void flatten(TreeNode* root) 
    {
        Help(root);
    }
};
// @lc code=end

TreeNode* BuildTree()
{
    int n;
    cin >> n;
    if(n == -1) return nullptr;
    TreeNode* root = new TreeNode(n);
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
    vector<int> a = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
    int i = 0;
    TreeNode* root = BuildTree();
    Solution sol;
    sol.flatten(root);

    return 0;
}