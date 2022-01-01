/*
@lc app=leetcode id=637 lang=cpp
 *
[637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> avgs;
        vector<int> level;
        q.push(root);
        q.push(nullptr);
        while(q.size())
        {
            TreeNode* front = q.front();
            q.pop();
            if(!front)
            {
                int sum = 0;
                for(int item : level) sum += (item / 1.0 * level.size());
                avgs.push_back(sum);
                level.clear();
                if(q.empty())
                    break;
                q.push(nullptr);
            }
            level.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return avgs;
    }
};
// @lc code=end

