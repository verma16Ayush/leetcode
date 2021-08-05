#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<int>> dp(points.size(), vector<int>(points[0].size(), INT32_MIN));
        dp[0] = points[0];
        for(int i = 1; i < points.size(); i++)
        {
            for(int j = 0; j < points[0].size(); j++)
            {
                for(int k = 0; k < points[0].size(); k++)
                {
                    dp[i][j] = max(dp[i][j], points[i][j] + dp[i - 1][k] - abs(j - k));
                }
            }
        }
        return *max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{1,2,3},{1,5,1},{3,1,1}};
    cout << Solution().maxPoints(a);

    return 0;
}