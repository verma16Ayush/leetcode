/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Node
{
public:
    vector<pair<int, Node*>> nbs; // from this node to neighbor node in time;
    int val;
    Node(int _val) : val(_val), nbs(vector<pair<int, Node*>>()) {}
};
class Solution {
public:
    unordered_map<int, Node*> nodes; // <NodeVal, Node*>;
    unordered_map<Node*, int> dist; // <Node, dist>
    set<pair<int, Node*> > st; // <dist , Node>

    void BuildGraph(vector<vector<int>>& times, int n)
    {
        for(int i = 1; i <= n; i++)
            nodes[i] = new Node(i);
        for(auto& t : times)
            nodes[t[0]]->nbs.push_back({t[2], nodes[t[1]]});
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        BuildGraph(times, n);
        for(auto& node : nodes)
            dist[node.second] = node.second->val == k ? 0 : INT16_MAX;

        st.insert({0, nodes[k]});

        while(st.size())
        {
            auto top = *st.begin();
            int nearestNodeDist = top.first;
            Node* nearestNode = top.second;
            st.erase(top);

            for(auto& nbs : nearestNode->nbs)
            {
                if(dist[nearestNode] + nbs.first < dist[nbs.second])
                {
                    pair<int, Node*> modifyNode = {dist[nbs.second], nbs.second};
                    if(st.count(modifyNode))
                        st.erase(modifyNode);
                    
                    dist[nbs.second] = dist[nearestNode] + nbs.first;
                    modifyNode.first = dist[nbs.second];
                    st.insert(modifyNode);
                }
            }
        }
        int mx = -1;
        for(auto p : dist)
            mx = max(mx, p.second);
        return mx >= INT16_MAX ? -1 : mx;
    }
};
// @lc code=end

