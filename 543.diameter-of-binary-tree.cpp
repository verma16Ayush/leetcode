/*
@lc app=leetcode id=543 lang=cpp
 *
[543] Diameter of Binary Tree
 */

// @lc code=start
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

class Solution {
public:
    int ans = 0;
    int Height(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int l_height = Height(root->left);
        int r_height = Height(root->right);
        ans = max(ans, l_height + r_height);
        return 1 + max(l_height, r_height);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        Height(root);
        return ans;   
    }
};
// @lc code=end

