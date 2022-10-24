/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> ans(n * n);
        for(int i = 0; i < n * n; i++)
            ans[i] = i + 1;

        vector<vector<int>> a(n, vector<int>(n));
        int up = 0, down = a.size() - 1;
        int left = 0, right = a[0].size() - 1;

        // vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int d = 0;
        int p = 1;
        while(true)
        {
            if(p > n * n) break;
            if(d == 0)
            {
                for(int i = left; i <= right; i++)
                {
                    a[up][i] = p++;
                    // ans.push_back();
                }
                up++;
                d = (d + 1) % 4;
            }

            if(p > n * n) break;
            if(d == 1)
            {
                for(int i = up; i <= down; i++)
                {
                    a[i][right] = p++;
                    // ans.push_back();
                }
                right--;
                d = (d + 1) % 4;
            }

            // if(ans.size() == (a.size() * a[0].size())) break;
            if(p > n * n) break;
            if(d == 2)
            {
                for(int i = right; i >= left; i--)
                {
                    a[down][i] = p++;
                    // ans.push_back();
                }
                down--;
                d = (d + 1) % 4;
            }

            // if(ans.size() == (a.size() * a[0].size())) break;
            if(p > n * n)
                break;
            if(d == 3)
            {
                for(int i = down; i >= up; i--)
                {
                    a[i][left] = p++;
                    // ans.push_back();
                }
                left++;
                d = (d + 1) % 4;
            }
        }
        return a;
    }
};
// @lc code=end

