#include <iostream>
#include <bits/stdc++.h>
#define nl '\n'
#define int ll
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
typedef long long ll;
using namespace std;

class Graph
{
public:
    map<int, list<int>> adjList;
    void AddEdge(int v, int u, int bidir = 1)
    {
        adjList[v].push_back(u);
        if(bidir) adjList[u].push_back(v);
    }

    void PrintAdjlist()
    {
        for(auto i : adjList)
        {
            cout << i.first << " -> ";
            for(int j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void Bfs(int src)
    {
        queue<int> q;
        map<int, bool> visited;
        visited[src] = true;
        q.push(src);

        while(!q.empty())
        {

            int fr = q.front();
            q.pop();
            for(int i : this->adjList[fr]) 
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
            cout << fr << " ";
        }
    }

    int BfsShortestPath(int src)
    {
        string str = "a"; str += 'a'
    }
};



int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    Graph g;
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(3, 2);
    g.AddEdge(3, 4);
    g.AddEdge(4, 5);
    g.PrintAdjlist();
    g.Bfs(*(g.adjList.begin()->second.begin()));
    return 0;
}