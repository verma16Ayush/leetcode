#include <bits/stdc++.h>
using namespace std;

int Peak(vector<int>& a)
{
    int st = 0;
    int en = a.size() - 1;
    while(st <= en)
    {
        int mid = st + (en - st) / 2;
        if(a[mid - 1] < a[mid] && a[mid + 1] < a[mid]) return mid;
        else if(a[mid - 1] < a[mid] && a[mid] < a[mid + 1]) st = mid + 1;
        else en = mid - 1;
    }
    return -1;
}


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector<int> a = {1,2,1};
    cout << Peak(a) << endl;
    return 0;
}