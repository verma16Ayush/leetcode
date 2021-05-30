/*
@lc app=leetcode id=101 lang=cpp
 *
[101] Symmetric Tree
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
    bool Check(TreeNode* rootleft, TreeNode* rootright)
    {
        if(!rootleft && !rootright) return true;
        if(rootright && !rootleft || !rootright && rootleft) return false;
        if(rootleft->val == rootright->val)
        {
            return Check(rootleft->left, rootright->right) && Check(rootleft->right, rootright->left);
        }
        return false;
    }
    bool CheckIter(TreeNode* root)
    {
        
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;
        return Check(root->left, root->right);
    }
};
// @lc code=end

// TreeNode* BuildTree()
// {
//     int t;
//     cin >> t;
//     if(t == -1) return nullptr;
//     TreeNode* root = new TreeNode();
//     root->val = t;
//     root->left = BuildTree();
//     root->right = BuildTree();
//     return root;
// }
// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
    
//     return 0;
// }