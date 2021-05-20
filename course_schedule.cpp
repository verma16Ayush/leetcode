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

        if(visited.find(source) == visited.end())
        {
            visited.insert(source);
            inStack.insert(source);

            for(auto n : source->neighbors)
            {
                if(visited.find(n) != visited.end() && inStack.find(n) != inStack.end()) return true;
                else if(DetectCycle(n)) return true;
            }
            inStack.erase(source);
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        BuildGraph(numCourses, prerequisites);
        bool res = false;
        auto iter = courseNodes.begin();
        while(visited.size() != numCourses && iter != courseNodes.end())
        { 
            if(visited.find(iter->second) == visited.end())
            {
                res = res || DetectCycle(iter->second);
            }
            iter++;
        }   
        return !res;
    }
};


int main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<vector<int>> prereq(2, vector<int>(2, 0));

    // for(vector<int> i : prereq)
    // {
    //     for(int j : i)
    //     {
    //         cin >> j;
    //     }
    // }

    for(int i = 0; i < prereq.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> prereq[i][j];
        }
    }
    Solution* sol = new Solution();
    cout << sol->canFinish(n, prereq) << endl;
    return 0;
}