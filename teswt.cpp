#include <bits/stdc++.h>
using namespace std;

vector<int> a;
struct cmp
{
    bool operator()(const int i, const int j) const
    {
        return a[i] < a[j];
    }
};

class Demo{
public:
    set<int, cmp> st;
    Demo() : st(set<int, cmp>()){}

    void Push()
    {
        for(int i = 0; i < a.size(); i++)
        {
            st.insert(i);
        }
    }

};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    a = {1,2,1};
    Demo d;
    d.Push();
    return 0;
}