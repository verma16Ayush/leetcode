/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) 
    {
        int up = 0, down = a.size() - 1;
        int left = 0, right = a[0].size() - 1;
        vector<int> ans;
        // vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int d = 0;
        while(true)
        {
            if(ans.size() == (a.size() * a[0].size())) break;
            if(d == 0)
            {
                for(int i = left; i <= right; i++)
                {
                    ans.push_back(a[up][i]);
                }
                up++;
                d = (d + 1) % 4;
            }

            if(ans.size() == (a.size() * a[0].size())) break;
            if(d == 1)
            {
                for(int i = up; i <= down; i++)
                {
                    ans.push_back(a[i][right]);
                }
                right--;
                d = (d + 1) % 4;
            }

            if(ans.size() == (a.size() * a[0].size())) break;
            if(d == 2)
            {
                for(int i = right; i >= left; i--)
                {
                    ans.push_back(a[down][i]);
                }
                down--;
                d = (d + 1) % 4;
            }

            if(ans.size() == (a.size() * a[0].size())) break;
            if(d == 3)
            {
                for(int i = down; i >= up; i--)
                {
                    ans.push_back(a[i][left]);
                }
                left++;
                d = (d + 1) % 4;
            }
        }
        return ans;
    }
};
// @lc code=end

void PrintMat(vector<vector<int>> a)
{
    for(vector<int> i : a)
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a(3, vector<int>(4));
    for(auto& i : a)
    {
        for(int& j : i) cin >> j;
    }
    PrintMat(a);
    Solution sol;
    vector<int> ans = sol.spiralOrder(a);

    return 0;
}