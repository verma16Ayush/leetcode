/*
@lc app=leetcode id=1448 lang=cpp
 *
[1448] Count Good Nodes in Binary Tree
 */

/**
Definition for a binary tree node.
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
class Solution
{
public:
    int ans;
    void help(TreeNode *root, int prevMax)
    {
        if (!root)
            return;
        if (root->val >= prevMax)
        {
            ans += 1;
            prevMax = root->val;
        }
        help(root->left, prevMax);
        help(root->right, prevMax);
    }
    int goodNodes(TreeNode *root)
    {
        help(root, INT32_MIN);
        return ans;
    }
};
// @lc code=end

TreeNode *BuildTree()
{
    int t;
    cin >> t;
    if (t == -1)
        return nullptr;
    auto root = new TreeNode(t);
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
    
    return 0;
}