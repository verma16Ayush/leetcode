/*
@lc app=leetcode id=538 lang=cpp
 *
[538] Convert BST to Greater Tree
 */
#include <bits/stdc++.h>
using namespace std;
/**
Definition for a binary tree node.
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
class Solution {
public:
    int sum;
    void DFSHelper(TreeNode* root)
    {
        if(!root)
            return;
        DFSHelper(root->right);
        sum += root->val;
        root->val = sum;
        DFSHelper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        DFSHelper(root);
        // for(int i = 1; i < temp.size(); i++)
        //     temp[i]->val += temp[i - 1]->val;
        return root;
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
    Solution().convertBST(root);
    return 0;
}
