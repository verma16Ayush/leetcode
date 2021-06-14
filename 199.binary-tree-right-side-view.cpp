/*
@lc app=leetcode id=199 lang=cpp
 *
[199] Binary Tree Right Side View
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
    void GetView(TreeNode* root, vector<int>& a)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> ans;
        vector<int> temp;
        while(q.empty() == false)
        {
            TreeNode* front = q.front();
            q.pop();
            if(front == nullptr)
            {
                ans.push_back(temp);
                temp = vector<int>();
                if(q.size() == 0) break;
                else q.push(nullptr);
            }
            else
            {
                temp.push_back(front->val);
                if(front->right) q.push(front->right);
                if(front->left) q.push(front->left);
            }
        }

        for(auto i : ans)
        {
            a.push_back(i[0]);
        }
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root) return {};
        vector<int> a;
        GetView(root, a);
        return a;
    }
};
// @lc code=end

// TreeNode* BuildLevelTree()
// {

// }

TreeNode* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1) return nullptr;
    TreeNode* root = new TreeNode(t);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto root = BuildTree();
    Solution sol;
    vector<int> ans = sol.rightSideView(root);
    return 0;
}