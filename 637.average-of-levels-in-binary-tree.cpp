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
        vector<int> level;
        vector<double> avg;
        q.push(root);
        q.push(nullptr);
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            if(front == nullptr)
            {
                auto sum = 0LL;
                for(int i : level)
                    sum += i;
                avg.push_back(sum / (1.0 * level.size()));
                level = vector<int>();
                if(q.empty())
                    break;
                q.push(nullptr);
                continue;
            }
            level.push_back(front->val);
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
                
        }
        return avg;
    }
};
// @lc code=end

