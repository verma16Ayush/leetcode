/*
@lc app=leetcode id=110 lang=cpp
 *
[110] Balanced Binary Tree
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

struct temp
{
    int h;
    int isBal;
};

class Solution {
public:
    int Height(TreeNode* root) {
        if(!root) return 0;
        int l = Height(root->left);
        int r = Height(root->right);
        return 1 + max(l, r);
    }

    temp help(TreeNode* root) {
        temp t;
        if(root == nullptr)
        {
            t.isBal = 1;
            t.h = 0;
            return t;
        }
        temp l = help(root->left);
        temp r = help(root->right);
        t.h = 1 + max(l.h, r.h);
        t.isBal = abs(l.h - r.h) <= 1 && l.isBal && r.isBal ? 1 : 0;
        return t;
    }

    bool isBalanced(TreeNode* root) {
        // if(!root) return true;
        // int l = Height(root->left);
        // int r = Height(root->right);
        // if(abs(l - r) > 1) return false;
        // return isBalanced(root->left) && isBalanced(root->right);

        auto t = help(root);
        return t.isBal;
    }
};
// @lc code=end

