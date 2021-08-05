/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

struct Node
{
    int val;
    vector<Node*> neighbors;
    Node(int _v) : val(_v), neighbors(vector<Node*>()) {}
    Node(int _v, vector<Node*> _nb) : val(_v), neighbors(_nb) {}
};

class Solution {
public:
    unordered_map<int, Node*> courseNodes;
    unordered_set<Node*> visited;
    unordered_set<Node*> inStack;
    vector<int> resstck;

    Solution() : 
        courseNodes(unordered_map<int, Node*>()), 
        visited(unordered_set<Node*>()),
        inStack(unordered_set<Node*>()),
        resstck(vector<int>()) {}

    void BuildGraph(vector<vector<int>>& pre, int n)
    {
        for(int i = 0; i < n; i++) courseNodes[i] = new Node(i);
        for(auto& i : pre)
        {
            courseNodes[i[1]]->neighbors.push_back(courseNodes[i[0]]);
        }
    }

    bool HasCycle(Node* source)
    {
        if(visited.find(source) == visited.end())
        {
            visited.insert(source);
            inStack.insert(source);
            for(auto t : source->neighbors)
            {
                if(visited.find(t) != visited.end() && inStack.find(t) != inStack.end()) return true;
                if(visited.find(t) == visited.end()) if(HasCycle(t)) return true;
            }
            inStack.erase(source);
        }
        return false;
    }

    void dfs(Node* source, vector<int>& st)
    {
        visited.insert(source);
        for(auto t : source->neighbors)
            if(visited.find(t) == visited.end()) 
                dfs(t, st);
        
        st.push_back(source->val);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        BuildGraph(prerequisites, numCourses);
        for(auto t : courseNodes)
        {
            if(visited.find(t.second) == visited.end()) 
                if(HasCycle(t.second)) 
                    return {};
        }

        visited = unordered_set<Node*>();
        for(int i = 0; i < numCourses; i++)
        {
            if(visited.find(courseNodes[i]) == visited.end()) 
                dfs(courseNodes[i], resstck);
        }
        reverse(resstck.begin(), resstck.end());
        return resstck;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{0, 1}};
    vector<int> re = Solution().findOrder(2, a);
    return 0;
}