/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        int carry = 0;
        int i = 0, j = 0;
        while(i < num1.size() || j < num2.size())
        {
            int s = (i < num1.size() ? num1[i] - '0' : 0) + (j < num2.size() ? num2[j] - '0' : 0) + carry;
            res += s % 10 + '0';
            carry = s / 10;
            i++;
            j++;
        }
        if(carry) res.append(to_string(carry));
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string num1 = "929";
    string num2 = "123";
    cout << Solution().addStrings(num1, num2);
    return 0;
}

