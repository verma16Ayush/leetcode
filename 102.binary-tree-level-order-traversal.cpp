/*
@lc app=leetcode id=102 lang=cpp
 *
[102] Binary Tree Level Order Traversal
 */

// // @lc code=start
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> ans;
        vector<int> temp;
        if(!root) return ans;
        while(q.size() > 1)
        {
            auto fr = q.front();
            q.pop();
            if(fr == nullptr)
            {
                ans.push_back(temp);
                temp.clear();
                q.push(nullptr);

            }
            else
            {    
                temp.push_back(fr->val);
                if(fr->left)q.push(fr->left);
                if(fr->right)q.push(fr->right);
            }
        }
        if(temp.size()) ans.push_back(temp);
        temp.clear();
        return ans; 
    }  
};

// @lc code=end

