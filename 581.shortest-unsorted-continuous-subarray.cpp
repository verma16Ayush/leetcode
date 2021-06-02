/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) // O(n)
    {
        int i = 0;
        int ires = 0;
        for(int i = 0; i + 1 < a.size(); i++)
        {
            if(a[i + 1] < a[i])
            {
                ires = i;
                break;
            }
        }

        int jres = a.size() - 1;
        for(int j = ires + 1; j + 1 < a.size(); j++)
        {
            if(a[j + 1] > a[j]) jres = 
        }
    }
    // int findUnsortedSubarray(vector<int>& nums) // O(nlogn)
    // {
    //     vector<int> cp = nums;
    //     int i = 0;
    //     int j = cp.size() - 1;
    //     sort(cp.begin(), cp.end());

    //     int flagi = 1;
    //     int flagj = 1;
    //     int ires = 0, jres = cp.size() - 1;
    //     for(i, j; i < cp.size() && 0 <= j && (flagi || flagj); i++, j--)    
    //     {
    //         if(nums[i] != cp[i] && flagi)
    //         {
    //             flagi = 0;
    //             ires = i;
    //         }

    //         if(nums[j] != cp[j] && flagj)
    //         {
    //             flagj = 0;
    //             jres = j;
    //         }
    //     }

    //     return is_sorted(nums.begin(), nums.end()) ? 0 : jres - ires + 1;
    // }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> a = {1,2,4,5,3};
    cout << sol.findUnsortedSubarray(a) << endl;
    return 0;
}