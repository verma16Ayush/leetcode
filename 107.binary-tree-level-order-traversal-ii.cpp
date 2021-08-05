/*
@lc app=leetcode id=107 lang=cpp
 *
[107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        // temp.push_back(root->val);
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            if(front == nullptr)
            {
                ans.push_back(temp);
                temp = vector<int>();
                if(q.empty()) break;
                q.push(nullptr);
                continue;
            }
            temp.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

