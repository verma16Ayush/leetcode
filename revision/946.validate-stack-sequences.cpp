/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while(j < popped.size())
        {
            if(i == pushed.size() && st.top() != popped[j])
                break;
            if(i != pushed.size())
                st.push(pushed[i++]);
            
            while(st.size() && j != popped.size() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {4,5,3,2,1};
    cout << Solution().validateStackSequences(a, b) << endl;
    return 0;
}