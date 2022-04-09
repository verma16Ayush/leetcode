/*
@lc app=leetcode id=450 lang=cpp
 *
[450] Delete Node in a BST
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TreeNode* FindKeyNode(TreeNode* root, int key)
    // {
    //     if(!root)
    //         return nullptr;
    //     if(root->val == key)
    //         return root;
    //     if(key > root->val)
    //         return FindKeyNode(root->right, key);
    //     return FindKeyNode(root->left, key);
    // }

    // TreeNode* FindSmallestNode(TreeNode* root)
    // {
    //     if(!root)
    //         return nullptr;
    //     if(root->left)
    //         return FindSmallestNode(root->left);
    //     return root;
    // }
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     TreeNode* keyNode = FindKeyNode(root, key);
    //     if(!keyNode)
    //         return root;
    //     if(keyNode->right == nullptr)
    //         return keyNode->left;
    //     if(keyNode->left == nullptr)
    //         return keyNode->right;
    //     TreeNode* smallestNodeRight = FindSmallestNode(keyNode->right);
    //     keyNode->val = smallestNodeRight->val;
    //     keyNode->right = deleteNode(keyNode->right, smallestNodeRight->val);
    //     return root;
    // }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(!root)
            return root;
        if(key > root->val)
            return deleteNode(root->right, key);
        if(key < root->val)
            return deleteNode(root->left, key);
        
        if(root->right == nullptr)
            return root-> 
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
    Solution sol;
    sol.deleteNode(root, 7);    
    return 0;
}