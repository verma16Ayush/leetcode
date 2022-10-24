#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastOccMin = -1;
        int firstOccMax = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == minK)
                lastOccMin = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maxK)
            {
                firstOccMax = i;
                break;
            }
        }
        if(lastOccMin == -1 || firstOccMax == -1)
            return 0;
        long long int c = 1;


    }
};
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {-1,2,-3,3};
    cout << Solution().sumOfNumberAndReverse(99999);
    return 0;
}