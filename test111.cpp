#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void help(string& s, int i, string temp)
{
    if(i == s.length())
    {
        ans.push_back(temp);
        return;
    }
    if(s[i] != '?')
    {
        temp.push_back(s[i]);
        help(s, i + 1, temp);
    }
    temp.push_back('0');
    help(s, i + 1, temp);
    temp.pop_back();
    temp.push_back('1');
    help(s, i + 1, temp);
    return;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "??";
    ans = vector<string>();
    string st = "";
    help(s, 0, st);
    for(string s : ans) cout << s << endl;

    return 0;
}