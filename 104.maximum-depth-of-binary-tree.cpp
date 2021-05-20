/*
@lc app=leetcode id=104 lang=cpp
 *
[104] Maximum Depth of Binary Tree
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root) return 0;
        else return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// @lc code=end

