/*
 * @lc app=leetcode id=1864 lang=cpp
 *
 * [1864] Minimum Number of Swaps to Make the Binary String Alternating
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) 
    {
        int n = s.length();
        int cz = 0;
        for(char i : s) if (i == '0') cz++;
        if(n % 2 == 0)
        {
            if(cz != n / 2) return -1;
            int t1 = 0, t2 = 0;
            for(int i = 0; i < n; i += 2)
            {
                if(s[i] != '0') t1++;
                if(s[i] != '1') t2++;
            }
            return min(t1, t2);
        }
        
        int co = n - cz;
        if(abs(cz - co) > 1) return -1;
        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i += 2)
        {
            if(s[i] == '0') t1++;
            if(s[i] == '1') t2++;
        }
        return co > cz ? t1 : t2;
    }
};
// @lc code=end

