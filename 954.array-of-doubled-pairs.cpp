/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        map<int, int> mp;
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) -> bool {
            return abs(a) < abs(b);
        });

        int c0 = 0;
        for(auto i : arr) 
        {
            if(i == 0) continue;
            mp[i]++;
            // st.insert(i);
        }
        for(auto i : arr)
        {
            if(mp.find(i * 2) != mp.end())
            {
                int k = min(mp[i], mp[i * 2]);
                mp[i] -= k;
                mp[i * 2] -= k;
            }
        }
        for(auto p : mp)
        {
            if(p.second != 0) 
                return 0;
        }
        return 1;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {-1,4,6,8,-4,6,-6,3,-2,3,-3,-8};
    cout << Solution().canReorderDoubled(a);
    return 0;
}

