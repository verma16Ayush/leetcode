/*
@lc app=leetcode id=113 lang=cpp
 *
[113] Path Sum II
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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int target, vector<int> temp)
    {
        if(!root) return;
        if(root->val == target && root->right == nullptr && root->left == nullptr)
        {
            ans.push_back(temp);
            return;
        }
        if(root->left)
        {
            temp.push_back(root->left->val);
            dfs(root->left, target - root->val, temp);
            temp.pop_back();
        }
        if(root->right)
        {
            temp.push_back(root->right->val);
            dfs(root->right, target - root->val, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return vector<vector<int>>();
        ans = vector<vector<int>>();
        vector<int> temp;
        temp.push_back(root->val);
        dfs(root, targetSum, temp);
        return ans;
    }
};
// @lc code=end

