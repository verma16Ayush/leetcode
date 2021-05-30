/*
@lc app=leetcode id=94 lang=cpp
 *
[94] Binary Tree Inorder Traversal
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
    vector<int> ans;
    void Helper(TreeNode* root)
    {
        if(!root) return;
        Helper(root->left);
        ans.push_back(root->val);
        Helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        // Helper(root);
        // return ans;
        stack<TreeNode*> todo;
        vector<int> ans;
        while(root || !todo.empty())
        {
            while(root)
            {
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            ans.push_back(root->val);
            todo.pop();
            root = root->right;
        }
        return ans;
    }
};
// @lc code=end

