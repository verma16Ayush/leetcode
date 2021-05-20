/*
@lc app=leetcode id=572 lang=cpp
 *
[572] Subtree of Another Tree
 */

// @lc code=start
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool IsEqual(TreeNode* s, TreeNode* t)
    {
        if(!s || !t) return s == t;
        if(s->val == t->val && IsEqual(s->left, t->left) && IsEqual(s->right, t->right)) return true;
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(s && t == nullptr || t && s == nullptr) return false;
        if(s == nullptr && t == nullptr) return true;
        if(IsEqual(s, t)) return true;
        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};
// @lc code=end

