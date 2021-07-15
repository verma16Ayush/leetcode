/*
@lc app=leetcode id=687 lang=cpp
 *
[687] Longest Univalue Path
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
    int ans;
    int Help(TreeNode* root, int val, int isRoot) {
        if(root == nullptr) return 0;
        if(root->val != val) return 0;
        if(!isRoot) return 1 + max(Help(root->left, val, 0), Help(root->right, val, 0));
        int cur = 1 + Help(root->left, val, 0) + Help(root->right, val, 0);
        
        int left = root->left ? Help(root->left, root->left->val, 1) : 0;
        int right = root->right ? Help(root->right, root->right->val, 1) : 0;
        ans = max({ans, cur, left, right});
        return cur;
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        if(!root) return 0;
        Help(root, root->val, 1);
        return ans - 1;
    }
};
// @lc code=end

