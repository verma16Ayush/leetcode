/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits;
        for(auto& word : words)
        {
            int k = 0;
            for(auto& letter: word)
            {
                k = k | (1 << (letter - 'a'));
            }
            bits.push_back(k);
        }
        int maxProd = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if((bits[i] & bits[j]) == 0)
                {
                    maxProd = max(maxProd, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return maxProd;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<string> a = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << Solution().maxProduct(a);
    return 0;
}