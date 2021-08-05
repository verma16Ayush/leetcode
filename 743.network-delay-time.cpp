/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

struct Node{
    int val;
    vector<pair<int, Node*>> neighbors; // to node in time
    Node() : 
        val(0), neighbors(vector<pair<int, Node*>>()) {}
    Node(int _v) : 
        val(_v), neighbors(vector<pair<int, Node*>>()) {}
};


class Solution {
public:
    unordered_map<int, Node*> nodes;
    void BuildGraph(vector<vector<int>>& times, int n)
    {
        for(int i = 1; i <= n; i++)
            nodes[i] = new Node(i);
        for(auto i : times)
        {
            nodes[i[0]]->neighbors.push_back({i[2], nodes[i[1]]});
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        BuildGraph(times, n);
        unordered_set<Node*> visited;
        set<pair<int, Node*>> st;
        unordered_map<Node*, int> dist;

        for(auto node : nodes)
            dist[node.second] = node.first == k ? 0 : INT16_MAX;

        st.insert({0, nodes[k]});
        while(st.size())
        {
            auto top = *st.begin();
            int top_node_dist = top.first;
            Node* top_node = top.second;
            st.erase(top);

            for(auto nb : top_node->neighbors)
            {
                if(top_node_dist + nb.first < dist[nb.second])
                {
                    auto node_to_ex = make_pair(dist[nb.second], nb.second);
                    if(st.find(node_to_ex) != st.end())
                        st.erase(node_to_ex);
                    
                    node_to_ex.first = top_node_dist + nb.first;
                    dist[nb.second] = node_to_ex.first;
                    st.insert(node_to_ex);
                }
            }
        }

        int mx = 0;
        for(auto p : dist)
            mx = max(p.second, mx);

        return mx >= INT16_MAX ? -1 : mx;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    

    return 0;
}
