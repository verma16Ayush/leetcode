/*
@lc app=leetcode id=230 lang=cpp
 *
[230] Kth Smallest Element in a BST
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
    pair<int, int> p;
    int kthSmallest(TreeNode* root, int k) 
    {
        static int count = 0;
        p.first = 0;
        p.second = 0;
        BuildInorder(root, k);
        return p.first;
    }
private:
    void BuildInorder(TreeNode* root, int k)
    {

        if(!root) return;
        BuildInorder(root->left, k);
        if(p.second == k) return;
        p.first = root->val;
        p.second += 1;
        BuildInorder(root->right, k);
    }
};
// @lc code=end

