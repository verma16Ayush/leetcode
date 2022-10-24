#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int BinSearc(vector<int>& potions, long long spellStrength, long long suc)
    {
        int st = 0, en = potions.size() - 1;
        while(st < en)
        {
            int mid = st + (en - st) / 2;
            if(spellStrength * potions[mid] >= suc)
                en = mid;
            else 
                st = mid + 1;
        }
        return potions.size() - en;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs(spells.size());
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++)
        {
            pairs[i] = BinSearc(potions, spells[i], success);
        }
        return pairs;
    }
};