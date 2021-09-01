/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char>a(26);
        for(int i = 0; i < order.length(); i++){
            a[order[i] - 'a'] = i;
        }
        return is_sorted(words.begin(), words.end(), [&](const string& w1, const string& w2)->bool{
            int i = 0;
            while(i < min(w1.length(), w2.length()) && w1[i] == w2[i]) 
                i++;
            if(i == min(w1.length(), w2.length())) 
                return w1.length() < w2.length();
            return a[w1[i] - 'a'] < a[w2[i] - 'a'];
        });
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<string> a = {"word","world","row"};
    string ordere = "worldabcefghijkmnpqstuvxyz";
    cout << Solution().isAlienSorted(a, ordere);
    return 0;
}