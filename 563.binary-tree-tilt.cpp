/*
@lc app=leetcode id=563 lang=cpp
 *
[563] Binary Tree Tilt
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
//pair<childSum, TiltVal>
class Solution {
public:
    int ans;
    pair<int, int> help(TreeNode* root)
    {
        if(!root) return {0, 0};
        auto lp = help(root->left);
        auto rp = help(root->right);
        ans += lp.second + rp.second;
        return {root->val + lp.first + rp.first, abs(lp.first - rp.first)};
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        ans += help(root).second;
        return ans;
    }
};
// @lc code=end

