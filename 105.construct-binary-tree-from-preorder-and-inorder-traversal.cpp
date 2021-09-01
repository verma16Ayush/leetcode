/*
@lc app=leetcode id=105 lang=cpp
 *
[105] Construct Binary Tree from Preorder and Inorder Traversal
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
private:
    unordered_map<int, int> mp;
    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder, int ps, int is, int ie)
    {
        if(is > ie) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int len1 = mp[preorder[ps]] - is;
        int len2 = ie - mp[preorder[ps]];

        root->left = buildTree2(preorder, inorder, ps + 1, is, mp[preorder[ps]] - 1);
        root->right = buildTree2(preorder, inorder, ps + len1 + 1, mp[preorder[ps]] + 1, ie);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.empty()) return nullptr;
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return buildTree2(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> pre = {3,9,20,15,7};
    vector<int> ino = {9,3,15,20,7};
    auto root = Solution().buildTree(pre, ino);
    return 0;
}