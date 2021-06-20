/*
@lc app=leetcode id=108 lang=cpp
 *
[108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* BuildTree(vector<int>& nums, int s, int e)
    {
        if(s > e) return nullptr;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BuildTree(nums, s, mid - 1);
        root->right = BuildTree(nums, mid + 1, e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return BuildTree(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

