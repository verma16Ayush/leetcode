#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;
    getline(cin, str);
    string s, s2;
    for(char c : str)
        if(c >= '0' && c <= '9')
            s += c;
    
    s2 = s;
    reverse(s2.begin(), s2.end());

    if(s == s2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}