/*
@lc app=leetcode id=111 lang=cpp
 *
[111] Minimum Depth of Binary Tree
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
class Solution {
public:
    int minDepthbfs(TreeNode* root)
    {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int i = 1;
        while(!q.empty())
        {
            auto fr = q.front();
            q.pop();
            if(fr == nullptr)
            {
                if(q.empty()) break;
                q.push(nullptr);
                i++;
                continue;
            }
            if(fr->left == nullptr && fr->right == nullptr) return i;
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        return -1;
    }
    int minDepth(TreeNode* root) {
        // if(!root) return 0;
        // if(!root->left && !root->right) return 1;
        // int l = root->left ? minDepth(root->left) : INT32_MAX;
        // int r = root->right ? minDepth(root->right) : INT32_MAX;
        // return 1 + min(l, r);
        return minDepthbfs(root);
    }
};
// @lc code=end

