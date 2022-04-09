/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {

public:
    vector<int> PrefixSum(vector<int>& a)
    {
        vector<int> ps(a.size());
        ps[0] = a[0];
        for(int i = 1; i < a.size(); i++)
        {
            ps[i] = a[i];
            ps[i] += ps[i - 1];
        }
        return ps;
    }
    bool canThreePartsEqualSum(vector<int>& arr) {
        auto ps = PrefixSum(arr);
        if(ps.back() % 3)
            return false;
        auto target = ps.back() / 3;
        int ii = -1;
        for(int i = 0; i < ps.size(); i++)
        {
            if(ps[i] == target)
            {
                ii = i;
                break;
            }
        }
        if(ii == -1)
            return false;
        int jj = -1;
        for(int j = ii + 1; j < ps.size() - 1; j++)
        {
            {
                if(ps[j] - ps[ii] == target)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,-1,1,-1};
    cout << Solution().canThreePartsEqualSum(a) << endl;
    return 0;
}

