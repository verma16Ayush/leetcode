/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val = 0, vector<Node*> _neighbors = vector<Node*>())
    {
        this->val = _val;
        this->neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_set<Node*> inStack;
    unordered_set<Node*> visited;
    unordered_map<int, Node*> courseNodes;

    void BuildGraph(int numCourses, vector<vector<int>> prereq)
    {
        for(int i = 0; i < numCourses; i++)
        {
            courseNodes[i] = new Node(i);
        }
        for(auto i : prereq)
        {
            courseNodes[i[1]]->neighbors.push_back(courseNodes[i[0]]);
        }
    }

    bool DetectCycle(Node* source)
    {

        visited.insert(source);
        inStack.insert(source);

        for(auto n : source->neighbors)
        {
            if(visited.find(n) != visited.end() && inStack.find(n) != inStack.end()) return true;
            if(visited.find(n) == visited.end()) if(DetectCycle(n)) return true;
        }
        inStack.erase(source);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        BuildGraph(numCourses, prerequisites);
        bool res = false;
        auto iter = courseNodes.begin();
        while(visited.size() != numCourses && courseNodes.end() != iter)
        { 
            if(visited.find(iter->second) == visited.end())
            {
                // visited.clear();
                res = res || DetectCycle(iter->second);
            }
            iter++;
        }   
        return !res;
    }

};
// @lc code=end

