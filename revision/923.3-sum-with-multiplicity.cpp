/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long result = 0;
        vector<long> count(101);
        long mod = 1000000007;
		
		//Couting the occurrence of each number
        for(int i: arr) count[i]++;
        
        for(int i=0;i<101;i++){
            for(int j=i;j<101;j++){
                int k = target - i -j;
                if(k<0 || k>100)
                    continue;
				// if all number are same than use nC3
                if(i==j && j==k){
                    result += (count[i]*(count[i]-1)*(count[i]-2))/6;
                }
				
				//if first two are same than use nC2 * occurence of k
                else if(i==j && j!=k){
                    result += ((count[i]*(count[i]-1))/2)*count[k];
                }
				//Last condition if all number ar different
				else if(i<j && j<k){
                    result += (count[i]*count[j]*count[k]);
                }
                result %= mod;
            }
        }
        return (int)result;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,1,2,2,3,3,4,4,5,5};
    int target = 8;
    cout << Solution().threeSumMulti(a, target);
    return 0;
}