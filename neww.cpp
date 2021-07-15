#include <bits/stdc++.h>
using namespace std;

int LCSubStr(vector<int>& X, vector<int>& Y, int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.  
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].
 
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        set<int> s;
        int ans = paths[0].size();
        int ref = 0;
        for(int i = 1; i < paths.size(); i++)
        {
            int lc = LCSubStr(paths[ref], paths[i], paths[ref].size(), paths[i].size());
            if(lc < ans)
            {
                ans = lc;
                ref = i;
            }
        }
        return ans;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {
                        {0,1,2,3,4},
                        {2,3,4},
                        {4,0,1,2,3}
                        };
    Solution sol;
    cout << sol.longestCommonSubpath(5, a);
    return 0;
}