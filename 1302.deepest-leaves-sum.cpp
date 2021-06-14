/*
@lc app=leetcode id=1302 lang=cpp
 *
[1302] Deepest Leaves Sum
 */

// @lc code=start
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
class Solution {
public:
    int ans;
    int add(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> ans;
        int sum = 0;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front == nullptr && q.empty()) break;
            else if(front == nullptr)
            {
                sum = 0;
                q.push(nullptr);
            }
            else
            {
                sum += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        return add(root);
    }
};
// @lc code=end

