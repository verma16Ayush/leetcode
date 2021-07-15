#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ifstream f1("input.txt", ios::binary);
    ofstream f2("output.txt", ios::binary);
    f2 << f1.rdbuf();
    return 0;
}