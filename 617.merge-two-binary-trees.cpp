/*
@lc app=leetcode id=617 lang=cpp
 *
[617] Merge Two Binary Trees
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
class Solution {
public:
    TreeNode* Merge(TreeNode* root1, TreeNode* root2)
    {
        TreeNode* root;
        if(!root1 && !root2) return root = nullptr;
        else if(root1 && root2) root = new TreeNode(root1->val + root2->val);
        else return root = root1 ? root1 : root2;
        root->left = Merge(root1->left, root2->left);
        root->right = Merge(root1->right, root2->right);
        return root;        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        return Merge(root1, root2);
    }
};
// @lc code=end
