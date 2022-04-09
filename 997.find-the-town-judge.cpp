/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution {
public:
    map<int, int > mp;
    int BuildGraph(int n, vector<vector<int>> trust)
    {
        for(auto i : trust)
        {
            mp[i[1]]++;
            mp[i[0]]--;
        }
        int judge = -1;
        for(int i = 1; i <= n; i++)
        {
            if(mp[i] == n - 1)
                return i;
        }
        return -1;
        
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        return BuildGraph(n, trust);
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{1, 2}};
    int n = 2;
    cout << Solution().findJudge(n, a);
    return 0;
}
