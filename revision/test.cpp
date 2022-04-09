#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int GetChildren(vector<int>& a, int pile)
    {
        int children = 0;
        for(int candies : a)
        {
            children += candies / pile;
        }
        return children;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int st = 0, en = *max_element(candies.begin(), candies.end());
        int mid;
        while(st < en)
        {
            mid = (st + en) / 2;
            int children = GetChildren(candies, mid);
            if(children > k)
                en = mid - 1;
            else
                st = mid + 1;
        }
        return st;
    }
};