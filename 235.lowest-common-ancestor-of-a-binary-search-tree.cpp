/*
@lc app=leetcode id=235 lang=cpp
 *
[235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* cur = root;
        while(true)
        {
            if(p->val > cur->val && q->val > cur->val) cur = cur->right;
            else if(p->val < cur->val && q->val < cur->val) cur = cur->left;
            else break;
        }
        return cur;
    }
};
// @lc code=endP

