/*
@lc app=leetcode id=95 lang=cpp
 *
[95] Unique Binary Search Trees II
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
    vector<TreeNode*> GenTree(int l, int r){
        vector<TreeNode*> roots;
        if(l > r)
        {
            roots.push_back(nullptr);
            return roots;
        }
        for(int i = l; i <= r; i++)
        {
            auto left = GenTree(l, i - 1);
            auto right = GenTree(i + 1, r);
            for(TreeNode* l_sub : left)
            {
                for(TreeNode* r_sub : right)
                {
                    roots.push_back(new TreeNode(i, l_sub, r_sub));
                }
            }
        }
        return roots;
    }
	vector<TreeNode*> generateTrees(int n) {
		return GenTree(1, n);
	}
};
// @lc code=end

