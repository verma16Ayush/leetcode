#include <bits/stdc++.h>
using namespace std;

int help(string s1, string s2)
{
    // string s1 = "somestring";
    // string s2 = "somestring2";
    string s1f = "", s2f = "";
    for(char c : s1)
    {
        if(c == '#')
        {
            if(s1f.size()) s1f.pop_back();
            continue;
        }
        s1f.push_back(c);
    }
    for(char c : s2)
    {
        if(c == '#')
        {
            if(s2f.size()) s2f.pop_back();
            continue;
        }
        s2f.push_back(c);
    }

    return (s1f == s2f);
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,2,1,1,2,3};
    a = help(a);
    return 0;
}