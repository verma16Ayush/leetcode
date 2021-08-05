/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    int ans;
public:
    
    int longestMountain(vector<int>& arr) {
        
        if(arr.size() <= 2) return 0;
        int ans = 0;
        int is_inc = 0;
        int is_dec = 0;
        for(int i = 1; i < arr.size() - 1; i++)
        {
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int j = i - 1, k = i + 1;
                while(j > 0 && arr[j - 1] < arr[j]) is_dec = 1, j--;
                while(k < arr.size() - 1 && arr[k + 1] < arr[k]) is_inc = 1, k++;
                ans = max(ans, k - j + 1);
                i = k;
            }
        }


        return ans; 
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {0,1,0};
    int ans = Solution().longestMountain(a);
    return 0;
}

