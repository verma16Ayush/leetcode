/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& a) 
    {
        int n = a.size();
        if(n < 3) return 0;
        sort(a.begin(), a.end());
        int count = 0;
        for(int i = n - 1; i > 1; i--)
        {
            int j = 0, k = i - 1;
            while(j < k)
            {
                if(a[j] + a[k] > a[i])
                {
                    count += k - j;
                    k--;
                }
                else j++;
            }
        }
        return count;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {2, 2, 3, 4};
    cout << Solution().triangleNumber(a);
    return 0;
}
