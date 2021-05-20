#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
struct pid
{
    int i;
    int time_to_process;
    int arr;
    pid(int i = 0, int time_to_process = 0, int arr = 0)
    {
        this->i = i;
        this->time_to_process = time_to_process;
        this->arr = arr;
    }
};

struct Cmp {
    bool operator()(pid const& p1, pid const& p2)
    {
        if(p1.time_to_process < p2.time_to_process) return true;
        // else if(p1.time_to_process > p2.time_to_process) return false;
        return p1.i < p2.i;

    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        vector<pid> prs(tasks.size());
        for(int i = 0; i < prs.size(); i++)
        {
            prs[i] = pid(i, tasks[i][1], tasks[i][0]);
        }
        priority_queue<pid, vector<pid>, Cmp> q;

        vector<int> ans;
        int i = 0;
        q.push(prs[i++]);
        while(i < prs.size() && prs[i].arr == prs[0].arr) q.push(prs[i++]);

        while(!q.empty())
        {
            pid fr = q.top();
            q.pop();
            ans.push_back(fr.i);
            while( i < prs.size() && prs[i].arr <= fr.arr + fr.time_to_process) q.push(prs[i++]);
        }

        return ans;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> prs(n, vector<int>(2));
        for(auto& i : prs)
        {
            for(auto& j : i) cin >> j;
        }
        Solution sol;
        
        for(auto i : sol.getOrder(prs)) cout << i << " ";
        cout << endl;
    }
}