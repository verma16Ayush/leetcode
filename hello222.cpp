#include <bits/stdc++.h>
using namespace std;

// class Solution{
// public:
//     int solve(vector<int>& a, int k);
// };


// int Solution::solve(vector<int> &a, int k) {
//     int n = a.size();
//     int i = n - k;
//     int s = 0, mx = 0;
//     for(i; i < a.size(); i++)
//         s += a[i];
    
//     for(int i = 0; i < k; i++)
//         a.push_back(a[i]);
    
//     i = n - k;
//     int j = n - 1;
//     while(i < n)
//     {
//         mx = max(s, mx);
//         s -= a[i++];
//         s += a[++j];
//     }
//     mx = max(s, mx);
//     return mx;

// }

// int32_t main()
// {
//     #ifdef LOCAL_PROJECT
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
    
//     vector<int> a = {-969, -948, 350, 150, -59, 724, 966, 430, 107, -809, -993, 337, 457, -713, 753, -617, -55, -91, -791, 758, -779, -412, -578, -54, 506, 30, -587, 168, -100, -409, -238, 655, 410, -641, 624, -463, 548, -517, 595, -959, 602, -650, -709, -164, 374, 20, -404, -979, 348, 199, 668, -516, -719, -266, -947, 999, -582, 938, -100, 788, -873, -533, 728, -107, -352, -517, 807, -579, -690, -383, -187, 514, -691, 616, -65, 451, -400, 249, -481, 556, -202, -697, -776, 8, 844, -391, -11, -298, 195, -515, 93, -657, -477, 587};
//     cout << Solution().solve(a, 81);
//     return 0;
// }

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> m(matrix.size(), 1);
        vector<int> n(matrix[0].size(), 1);
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; i < matrix[0].size(); j++)
                if(matrix[i][j] == 0) m[i] = n[j] = 0;
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(m[i] == 0 || n[j] == 0) matrix[i][j] = 0;
            }
        }
    }
};