#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.size();
        int k = 0;
        unordered_map<char, int> mp;
        for(char c = 'a'; c <= 'z'; c++)
            mp[c] = k++;

        char prev = 'a';
        for(char c : word)
        {
            int right = max(mp[c], mp[prev]);
            int left = min(mp[c], mp[prev]);
            int d1 = right - left;
            int d2 = 26 - right + left;
            ans += min(d1, d2);
            prev = c;
        }
        return ans;
    }
};


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string word = "bza";
    cout << Solution().minTimeToType(word);
    return 0;
}