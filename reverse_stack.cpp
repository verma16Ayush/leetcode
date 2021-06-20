#include <bits/stdc++.h>
using namespace std;

void insert_at_end(stack<int>& st, int val)
{
    if(st.empty()) 
    {
        st.push(val); return;
    }
    int t = st.top();
    st.pop();
    insert_at_end(st, val);
    st.push(t);
}


void reverse_stack(stack<int>& st)
{
    if(st.size() == 0) return;
    int t = st.top();
    st.pop();
    reverse_stack(st);
    insert_at_end(st, t);
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse_stack(st);
    while(st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }
    // insert_at_end(st, 6);
    return 0;
}