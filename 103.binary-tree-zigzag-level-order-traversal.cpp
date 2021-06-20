/*
@lc app=leetcode id=103 lang=cpp
 *
[103] Binary Tree Zigzag Level Order Traversal
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
/**
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void InsertInOrder(vector<int>& temp, int order)
    {
        if(order % 2)
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else ans.push_back(temp);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int order = 0;
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            if(front == nullptr)
            {
                if(q.empty()) break;
                InsertInOrder(temp, order++);
                temp = vector<int>();
                q.push(nullptr);
                continue;
            }
            temp.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        InsertInOrder(temp, order++);
        return ans;
    }
};
// @lc code=end

TreeNode* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1) return nullptr;
    auto root = new TreeNode(t);
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
    TreeNode* root = BuildTree();
    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);
    return 0;
}
