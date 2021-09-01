/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// typedef long long int;
struct Node{
    int val;
    vector<pair<Node*, int>> nbs;
    Node() : 
        val(0), nbs(vector<pair<Node*, int>> ()) {}
    Node(int _val) : 
        val(_val), nbs(vector<pair<Node*, int>>()) {}
};

class Solution {
public:
    unordered_map<int, Node*> mp;
    int ans;
    int mxstp;
    unordered_set<Node*> sk;
    void BuildGraph(int n, vector<vector<int>>& flights)
    {
        for(int i = 0; i < n; i++)
            mp[i] = new Node(i);
        for(auto flight : flights)
            mp[flight[0]]->nbs.push_back({mp[flight[1]], flight[2]});
    }

    // dfs with pruning. Dense Graph Big Bad
    void dfs(Node* src, Node* dst, int cost, int stops)
    {
        if(src == dst) 
        {
            ans = min(ans, cost);
            return;
        }
        if(cost > ans || stops > mxstp) 
            return;
        for(auto nb : src->nbs)
        {
            if(sk.find(nb.first) != sk.end())
                continue;
            sk.insert(src);
            dfs(nb.first, dst, cost + nb.second, stops + 1);
            sk.erase(src);
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        BuildGraph(n, flights);
        // node: distaance : stops
        unordered_map<Node*, int> dist;
        unordered_map<Node*, int> stop;
        stack<tuple<int, int, Node*>> st;
        for(int i = 0; i < n; i++)
            dist[mp[i]] = INT32_MAX;
        
        dist[mp[src]] = 0;
        

        st.push({0, 0, mp[src]});
        while(st.size())
        {
            auto top = st.top();
            st.pop();
            int top_dist = get<0>(top);
            int top_stops = get<1>(top);
            Node* top_node = get<2>(top);

            if(top_stops > k)
                break;

            for(auto nb : top_node->nbs)
            {
                int newdist = top_dist + nb.second;
                int newstp = top_stops + 1;
                if(newdist < dist[nb.first])
                {
                    dist[nb.first] = newdist;
                    st.push(make_tuple(newdist, newstp, nb.first));
                }
                // else if(newstp < stop[nb.first])
                // {
                //     st.push(make_tuple(newdist, newstp, nb.first));
                //     stop[nb.first] = newstp;
                // }
            }
        }
        return dist[mp[dst]] == INT32_MAX ? -1 : dist[mp[dst]];
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    cout << Solution().findCheapestPrice(4, a, 0, 3, 1);
    return 0;
}