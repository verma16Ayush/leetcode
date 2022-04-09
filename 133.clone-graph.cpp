/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int val;
    vector<Node*> neighbors;
    Node() 
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) 
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start

class Solution 
{
public:
    // Node* cloneGraph(Node* node) 
    // {
    //     static unordered_map<Node*, Node*> copies;
    //     if(!node) return nullptr;
    //     if(copies.find(node) != copies.end()) return copies[node];
        
    //     copies[node] = new Node(node->val);
    //     for(Node* adj : node->neighbors)
    //     {
    //         copies[node]->neighbors.push_back(cloneGraph(adj));
    //     }
    //     return copies[node];
    // }

    Node* cloneGraph(Node* node)
    {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            auto fr = q.front();
            q.pop();
            if(copies.find(fr) == copies.end())
            {
                copies[fr] = new Node(fr->val);
            }

            for(auto adj : fr->neighbors)
            {
                if(copies.find(adj) == copies.end())
                {
                    copies[adj] = new Node(adj->val);
                    q.push(adj);
                }
                copies[fr]->neighbors.push_back(copies[adj]);
            }
        }
        return copies[node];
    }
};
// @lc code=end

