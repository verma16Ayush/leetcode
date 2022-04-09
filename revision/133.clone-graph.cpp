/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

/*
// Definition for a Node.
*/
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start

class Solution {
public:
    set<Node*> visited;
    map<Node*, Node*> mp_cp;
    Solution() : 
        visited(set<Node*>()), 
        mp_cp(map<Node*, Node*>()) 
        {}

    void DeepCopy(Node* node)
    {
        if(!node || visited.count(node))
            return;
        if(!mp_cp.count(node))
            mp_cp[node] = new Node(node->val);
        for(auto nb : node->neighbors)
        {
            if(!mp_cp.count(nb))
                mp_cp[nb] = new Node(nb->val);
            mp_cp[node]->neighbors.push_back(mp_cp[nb]);
        }
        visited.insert(node);
        for(auto nb : node->neighbors)
            DeepCopy(nb);
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        DeepCopy(node);
        return mp_cp[node];
    }
};
// @lc code=end

