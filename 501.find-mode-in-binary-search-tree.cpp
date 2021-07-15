/*
@lc app=leetcode id=501 lang=cpp
 *
[501] Find Mode in Binary Search Tree
 */

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
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> ans;
    int k = 0;
    void help(TreeNode* root, int curmax = 0)
    {
        if(!root) return;
        hel
    }
    vector<int> findMode(TreeNode* root) {
        
    }
};
// @lc code=end

