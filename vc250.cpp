#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> mp(26, 0);
        for(char c : brokenLetters) mp[c - 'a'] = 1;
        string temp = "";
        int c = 0;
        istringstream ss(text);
        while(ss >> temp)
        {
            int flag = 1;
            for(char c : temp)
            {
                if(mp[c - 'a']) 
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) c++;
        }
        return c;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "leet code";
    string b = "e";
    cout << Solution().canBeTypedWords(s, b);
    return 0;
}