/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int i;
    vector<string> a;
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string s;
        while(getline(ss, s, ','))
            a.push_back(s);
        vector<string> st;
        if(a.size() == 1 && a.back() == "#") return 1;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == "#")
            {
                if(st.size() == 0)
                    return 0;
                if(st.back() == "#")
                {
                    while(st.size() && st.back() == "#")
                    {
                        st.pop_back();
                        if(st.size() == 0)
                            return 0;
                        st.pop_back();
                    }
                    // i -= 1;
                }
            }
            st.push_back(a[i]);

        }
        return st.size() == 1 ? (st.back() == "#" ? 1 : 0) : 0;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string pre = "#";
    // string pre = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    auto a = Solution().isValidSerialization(pre);
    return 0;
}