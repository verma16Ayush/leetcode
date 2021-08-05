/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

struct Node{
    int val;
    vector<Node*> neighbors;
    Node(int v = 0)
    {
        this->val = v;
    }
};
class Solution {
public:
    map<int, Node*> courseNodes;
    unordered_set<Node*> visited;
    void BuildGraph(vector<vector<int>>& isConnected)
    {
        for(int i = 0; i < isConnected.size(); i++)
        {
            for(int j = 0; j < isConnected[0].size(); j++)
            {
                if(isConnected[i][j] == 1)
                {
                    if(courseNodes.find(i) == courseNodes.end())
                        courseNodes[i] = new Node(i);
                    if(courseNodes.find(j) == courseNodes.end())
                        courseNodes[j] = new Node(j);
                    
                    if(i != j)
                    {
                        courseNodes[i]->neighbors.push_back(courseNodes[j]);
                        // mp[j]->neighbors.push_back(mp[i]);
                    }
                }
            }
        }
    }

    void dfs(Node* start)
    {
        for(auto i = start->neighbors.begin(); i != start->neighbors.end(); i++)
        {
            if(visited.find(*i) != visited.end()) continue;
            else
            {
                visited.insert(*i);
                dfs(*i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        BuildGraph(isConnected);
        int c = 0;
        for(auto i : courseNodes)
        {
            if(visited.find(i.second) == visited.end())
            {
                c++;
                dfs(i.second);
            }
        }
        return c;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    cout << Solution().findCircleNum(graph);
    return 0;
}