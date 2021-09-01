/*
@lc app=leetcode id=1339 lang=cpp
 *
[1339] Maximum Product of Splitted Binary Tree
 */

/**
Definition for a binary tree node.
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
typedef long long ll;
class Solution {
public:
    ll ans;
    ll Sum(TreeNode* root)
    {
        if(!root) return 0;
        root->val = root->val + Sum(root->left) + Sum(root->right);
        return root->val;
    }
    void Help(TreeNode* root, ll val)
    {
        if(!root) return;
        ans = max(ans, (val - root->val) * root->val);
        Help(root->left, val);
        Help(root->right, val);
    }
    ll maxProduct(TreeNode* root) {
        if(!root) return 0;
        Sum(root);
        ans = 0;
        Help(root, root->val);
        return (int)(ans % ((ll)1e9 + 7));
    }
};
// @lc code=end

