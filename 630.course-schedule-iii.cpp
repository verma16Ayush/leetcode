/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int FindAns(vector<vector<int>>& crs, int n, int cd)
    {
        if(dp[n][cd] != -1)
            return dp[n][cd];
        if(n == 0)
            return dp[n][cd] = 0;
        else if(cd + crs[n - 1][0] <= crs[n - 1][1])
            return dp[n][cd] = max(1 + FindAns(crs, n - 1, cd + crs[n - 1][0]), FindAns(crs, n - 1, cd));
        return dp[n][cd] = FindAns(crs, n - 1, cd);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.rbegin(), courses.rend(), [&](const vector<int>& a, const vector<int>& b)->bool{
            if(a[1] != b[1])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        dp = vector<vector<int>>((int)1e4, vector<int>((int)1e4, -1));
        FindAns(courses, courses.size(), 0);
        int mx = -1;
        for(auto i : dp)
        {
            mx = *max_element(i.begin(), i.end());
        }
        return mx;

        // int count = 0;
        // int curday = 0;
        // for(int i = 0; i < courses.size(); i++)
        // {
        //     if(curday + courses[i][0] <= courses[i][1])
        //     {
        //         curday += courses[i][0];
        //         count++;
        //     }
        // }
        // return count;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{5, 18}, {8, 17}, {1, 18}, {3, 6}, {2, 12}, {2, 13}};
    cout << Solution().scheduleCourse(a);
    return 0;
}