/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int GenGray(int n)
    {
        int msb = -1;
        vector<int> temp(32);
        for(int i = 31; i >= 0; i--)
        {
            if(n & i)
            {
                msb = i;
                temp[i] = 1;
                break;
            }
        }
        return 0;
    }
    vector<int> grayCode(int n) {
        vector<int> v;
        int num = 0;
        for(int i=0; i < (1<<n) ; i++)
        {
            num = i ^ (i >> 1);
            v.push_back(num);
        }
        return v;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> a = sol.grayCode(3);
    for(int i : a) cout << i << " ";
    return 0;
}