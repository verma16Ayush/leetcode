#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int num = 782;
    int c = 0;
    while(num != 0)
    {
        num = num / 10;
        c++;
    }
    cout<< c;
    return 0;
}