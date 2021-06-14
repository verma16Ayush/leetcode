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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    // ~ 1200ms, still AC tho
    // bool dfs(TreeNode* root, TreeNode* target)
    // {
    //     if(root == nullptr) return false;
    //     if(root == target) return true;
    //     return dfs(root->left, target) || dfs(root->right, target);
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    // {
    //     if(!root) return root;
    //     if(root == p || root == q) return root;

    //     bool found_p_in_left = dfs(root->left, p);
    //     bool found_p_in_right = dfs(root->right, p);

    //     bool found_q_in_left = dfs(root->left, q);
    //     bool found_q_in_right = dfs(root->right, q);

    //     if((found_p_in_left && found_q_in_right) || (found_q_in_left && found_p_in_right)) return root;
    //     else if(found_p_in_left) return lowestCommonAncestor(root->left, p, q);
    //     return lowestCommonAncestor(root->right, p, q);
    // }

    // ~400ms
    bool dfs(TreeNode* root, TreeNode* t1, TreeNode* t2)
    {
        if(root == nullptr) return root;
        if(root == t1 || root == t2) return root;
        return dfs(root->left, t1, t2) || dfs(root->right, t1, t2);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root) return root;
        if(root == p || root == q) return root;

        auto res1 = dfs(root->left, p, q);
        auto res2 = dfs(root->right, p, q);

        if(res1 && res2) return root;
        else if(res1) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
    
};
// @lc code=end