/** 
 *
 * @author - Ayush
 * @title - clone_graph.cpp
 * @createdOn - 2021-04-06 10:06 Hrs
 * 
 **/
#include <iostream>
#include <bits/stdc++.h>
#define nl '\n'
#define int ll
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
typedef long long ll;
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val = 0, vector<Node*> _neighbors = vector<Node*>() )
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Graph
{

};

void AddEdge(int _u, int _v, int bidir = 1)
{
    Node* u = new Node(_u);
    Node* v = new Node(_v);
    u->neighbors.push_back(v);
    if(bidir) v->neighbors.push_back(u);
}

Node* CreateGraph()
{
    // Node* n1 = new Node(1);
    // Node* n2 = new Node(2);
    // Node* n3 = new Node(3);
    // Node* n4 = new Node(4);
    // Node* n5 = new Node(5);
    
    // n1->neighbors = {n2, n3, n4, n5};
    // n2->neighbors = {n3, n4, n3};
    // n3->neighbors = {n2, n5, n1};
    // n4->neighbors = {n5, n1, n2};
    // n5->neighbors = {n1, n4, n3};

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    return n1;
}

void BreadthFirstSearch(Node* src)
{
    queue<Node*> q;
    q.push(src);
    unordered_set<Node*> visited;
    visited.insert(src);
    while(!q.empty())
    {
        auto fr = q.front();
        q.pop();
        cout << fr->val << " ";
        for(Node* i : fr->neighbors)
        {
            if(visited.find(i) == visited.end())
            {
                q.push(i);
                visited.insert(i);
            }
        }
    }
}

// void DepthFirstSearch(Node* source)
// {
//     if(visited.find(source) != visited.end()) return;
//     cout << source->val << " ";
//     visited.insert(source);
//     for(Node* i : source->neighbors)
//     {
//         DepthFirstSearch(i);
//     }
// }

unordered_set<Node*> visited;
Node* cloneGraph(Node* node) 
{
    static unordered_map<Node*, Node*> copies;
    if(!node) return nullptr;
    if(copies.find(node) != copies.end()) return copies[node];
    
    copies[node] = new Node(node->val);
    visited.insert(node);
    for(Node* adj : node->neighbors)
    {
        copies[node]->neighbors.push_back(cloneGraph(adj));
    }
    return copies[node];
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    Node* source = CreateGraph();
    BreadthFirstSearch(source);
    cout << nl;
    // DepthFirstSearch(source);
    Node* source2 = cloneGraph(source);
    BreadthFirstSearch(source2);
    return 0;
}