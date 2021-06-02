/*
@lc app=leetcode id=236 lang=cpp
 *
[236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

};
// @lc code=end

TreeNode* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1) return nullptr;
    TreeNode* root = new TreeNode();
    root->val = t;
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
    cout << sol.lowestCommonAncestor(root, root->left, root->right)->val << endl;
    return 0;
}
