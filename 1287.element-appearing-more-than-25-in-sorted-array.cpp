/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int k = arr.size() / 4;
        int i = 0, j = k;

        for(;j < arr.size();)
        {
            if(arr[i] == arr[j]) return arr[i];
            else
            {
                i++;
                j++;
            } 
        }
        return 0;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,2,3,3};
    Solution sol;
    cout << sol.findSpecialInteger(a) << endl;
    return 0;
}