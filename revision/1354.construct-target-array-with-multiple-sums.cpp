/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string solve(long long K, string S)
    {
        vector<char> arr;
        for(char c : S)
            arr.push_back(c);
        for(int i = 0; i < K; i++)
        {
            arr[0] = arr[0] == 'X' ? 'O' : 'X';
            bool prevTrans = true;
            for(int i = 1; i < arr.size(); i++)
            {
                if(prevTrans)
                {
                    if(arr[i - 1] == 'X')
                    {
                        arr[i] = arr[i] == 'X' ? 'O' : 'X';
                    }
                    else
                    {
                        prevTrans = false;
                    }
                }
            }
        }
        string ans = "";
        for(char c : arr)
            ans += c;
        return ans;

    }
};
// @lc code=end
