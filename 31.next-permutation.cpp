/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& a) 
    {
        if(is_sorted(a.rbegin(), a.rend()))
        {
            reverse(a.begin(), a.end());
            return;
        }
        int i;
        for(i = a.size() - 1; i - 1 >= 0; i--)
        {
            if(a[i - 1] >= a[i]) continue;
            else break; 
        }
        int k = i - 1;
        for(i = a.size() - 1; i >= 0; i--)
        {
            if(a[i] > a[k])
            {
                swap(a[i], a[k]);
                break;
            }
        }
        reverse(&a[k + 1], &a[a.size()]);
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector<int> a = {1, 2, 3};
    Solution sol;
    sol.nextPermutation(a);
    for(int i : a) cout << i << " ";
    cout << endl;

    return 0;
}