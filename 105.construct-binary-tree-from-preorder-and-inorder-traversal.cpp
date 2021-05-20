/*
@lc app=leetcode id=105 lang=cpp
 *
[105] Construct Binary Tree from Preorder and Inorder Traversal
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
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int s, int e)
    {
        if(s > e) return nullptr;
        TreeNode* root = nullptr;
        static int k = 0;
        int f = -1;
        for(int i = s; i <= e; i++)
        {
            if(inorder[i] == preorder[k])
            {
                f = i;
                break;
            } 
        }
        if(f != -1)
        {
            root = new TreeNode();
            root->val = preorder[k];
            k++;
            root->left = buildTree(preorder, inorder, s, f - 1);
            root->right = buildTree(preorder, inorder, f + 1, e);
        }
        // else return nullptr;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        return buildTree(preorder, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

