/*
@lc app=leetcode id=968 lang=cpp
 *
[968] Binary Tree Cameras
 */

#include <bits/stdc++.h>
using namespace std;
/**
Definition for a binary tree node.
 */
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
    enum state {MONITORED_NOCAM, HAS_CAM, UNMONITORED};
    int cams;
    int DfsHelp(TreeNode* root)
    {
        if(!root)
            return state::MONITORED_NOCAM;
        auto left = DfsHelp(root->left);
        auto right = DfsHelp(root->right);
        if(left == state::UNMONITORED || right == state::UNMONITORED)
        {
            cams++;
            return state::HAS_CAM;
        }
        if(left == state::HAS_CAM || right == state::HAS_CAM)
            return state::MONITORED_NOCAM;
        return state::UNMONITORED;
    }
    int minCameraCover(TreeNode* root) {
        // cout << state::MONITORED_NOCAM;
        if(!root)
            return 0;
        int top = DfsHelp(root);
        return cams + (top == state::UNMONITORED ? 1 : 0);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution().minCameraCover(nullptr);
    return 0;
}