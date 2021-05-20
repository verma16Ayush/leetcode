/*
@lc app=leetcode id=98 lang=cpp
 *
[98] Validate Binary Search Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool isValidBST(TreeNode* root, long long min, long long max)
    {
        if(!root) return true;
        return (root->val > min) && (root->val < max) && isValidBST(root->right, root->val, max) && isValidBST(root->left, min, root->val);
    }
    bool isValidBST(TreeNode* root) 
    {
        return isValidBST(root, INT64_MIN, INT64_MAX);
    }
};
// @lc code=end

