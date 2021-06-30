/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

#include<bits/stdc++.h>
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
    int ans = INT32_MIN;
    int help(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int get_left = max(help(root->left), 0);
        int get_right = max(help(root->right), 0);
        int cur_max = root->val + get_left + get_right;
        ans = max(cur_max, ans);
        return root->val + max(get_left, get_right);
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return ans;
    }
};
// @lc code=end

