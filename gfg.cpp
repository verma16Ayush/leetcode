#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxLength(string s){
        int i = 0;
        vector<char> st;
        int mx = 0;
        int curMax = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push_back(s[i]);
            }
            if(s[i] == ')')
            {
                if(st.size() && st.back() == '(')
                {
                    curMax += 2;
                    st.pop_back();
                    continue;
                }
                else
                {
                    st.clear();
                    mx = max(mx, curMax);
                    curMax = 0;
                    continue;
                }
            }
        }
        mx = max(mx, curMax);
        return mx;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "()(()";
    cout << Solution().maxLength(s);
    return 0;
}