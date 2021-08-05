/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int c1 = 0;
        for(int i : arr) c1 += (i == 1);
        if(c1 == 0) return {0, (int)arr.size() - 1};
        if(c1 % 3) return {-1, -1};
        int k = c1 / 3;


        int s = -1, m = -1, e = -1;
        c1 = -1;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 1) 
            {
                c1++;
                if(c1 % k == 0)
                {
                    if(s == -1) s = i;
                    else if(m == -1) m = i;
                    else if(e == -1) e = i;
                }
            }
        }

        while(e < arr.size())
        {
            if(arr[s] == arr[m] && arr[m] == arr[e]) s++, m++, e++;
            else break;
        }
        if(e == arr.size()) return {s - 1, m};

        return {-1, -1};
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,0,1,0,1};
    auto k = Solution().threeEqualParts(a);
    cout << k[0] << " " << k[1];
    return 0;
}