/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct Node{
    int val;
    vector<Node*> neighbors;
    Node(int _v = 0) : val(_v), neighbors(vector<Node*>()) {}
};
class Solution {
public:
    unordered_map<int, Node*> courseNodes;
    unordered_set<Node*> visited;
    int dp[100][100];

    Solution() : courseNodes(unordered_map<int, Node*>()), visited(unordered_set<Node*>()) {}
    void BuildGraph(int n, vector<vector<int>>& pre)
    {
        for(int i = 0; i < n; i++)
            courseNodes[i] = new Node(i);
        for(auto i : pre) 
        {
            courseNodes[i[0]]->neighbors.push_back(courseNodes[i[1]]);
        }
    }

    bool dfs(Node* source, Node* dest)
    {
        if(dp[source->val][dest->val] != -1)
            return dp[source->val][dest->val];
        if(source == dest) 
            return dp[source->val][dest->val] = 1;
        bool b = 0;
        visited.insert(source);
        for(auto nb : source->neighbors)
        {
            if(visited.find(nb) == visited.end()) 
                b = b || dfs(nb, dest);
            if(b) 
                return dp[source->val][dest->val] = b;
        }
        return dp[source->val][dest->val] = b;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        memset(dp, -1, sizeof(dp));
        BuildGraph(numCourses, prerequisites);
        vector<bool> ans(queries.size(), false);
        for(int i = 0; i < queries.size(); i++)
        {
            visited = unordered_set<Node*>();
            ans[i] = dfs(courseNodes[queries[i][0]], courseNodes[queries[i][1]]);
        }
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> courses = {{1, 0}};
    vector<vector<int>> queries = {{0, 1}, {1, 0}};
    Solution().checkIfPrerequisite(2, courses, queries);
    return 0;
}