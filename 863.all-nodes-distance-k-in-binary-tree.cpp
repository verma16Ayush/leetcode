/*
@lc app=leetcode id=863 lang=cpp
 *
[863] All Nodes Distance K in Binary Tree
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start

class Node
{
    public:
        int val;
        vector<Node*> nbs;
        Node() : val(0), nbs(vector<Node*>()) {}
        Node(int val_) : val(val_), nbs(vector<Node*>()) {}
};

class Solution {
public:
    unordered_map<TreeNode*, Node* > mp;

    void BuildNodes(TreeNode* root)
    {
        if(!root)
            return;
        mp[root] = new Node(root->val);
        BuildNodes(root->left);
        BuildNodes(root->right);
    }

    void BuildGraph(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
        {
            mp[root]->nbs.push_back(mp[root->left]);
            mp[root->left]->nbs.push_back(mp[root]);
        }

        if(root->right)
        {
            mp[root]->nbs.push_back(mp[root->right]);
            mp[root->right]->nbs.push_back(mp[root]);
        }

        BuildGraph(root->left);
        BuildGraph(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target = nullptr, int k = 0) 
    {
        // Connect(nullptr, root);
        BuildNodes(root);
        BuildGraph(root);
        queue<Node*> q;
        q.push(mp[target]);
        q.push(nullptr);
        vector<int> lvl;
        // lvl.push_back(mp[target]->val);
        if(k == 0)
            return {target->val};
        unordered_set<Node*> visited;
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            if(front == nullptr)
            {
                k--;
                if(!k)
                    return lvl;
                if(q.empty())
                    break;
                lvl = vector<int>();
                q.push(nullptr);
                continue;
            }
            visited.insert(front);

            for(auto nb : front->nbs)
            {
                if(visited.find(nb) == visited.end())
                {
                    q.push(nb);
                    lvl.push_back(nb->val);
                }
                
            }
            
        }
        return {};
    }
};
// @lc code=end

TreeNode* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1)
        return nullptr;
    TreeNode* root = new TreeNode(t);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto root = BuildTree();
    auto sol = Solution();
    sol.distanceK(root);
    return 0;
}