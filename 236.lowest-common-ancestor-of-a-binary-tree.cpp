/*
@lc app=leetcode id=236 lang=cpp
 *
[236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* LCA(TreeNode* root, int l, int h)
    {
        if(!root) return nullptr;
        if(root->val >= l && root->val < h) return root;
        if(root->val <= l) return LCA(root->left, l, h);
        if(root->val > h) return LCA(root->right, l, h);
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p->val, q->val);
    }
};
// @lc code=end



int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}
