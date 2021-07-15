/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // int seive[(uint32_t)5e6 + 1];
    vector<int> seive;
    void calcSeive(int n)
    {
        seive[0] = 0;
        seive[1] = 0;
        for(int i = 2; i * i <= n; i++)
        {
            if(seive[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    seive[j] = 0;
                }
            }
        }
    }
    int countPrimes(int n) {
        if(n <= 1) return 0;
        seive = vector<int>(n + 1, -1);
        // memset(&seive[0], -1, seive.size() * sizeof(int));
        calcSeive(n);
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(seive[i]) c += 1;
        }
        return c;
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
    cout << sol.countPrimes(0);
    return 0;
}