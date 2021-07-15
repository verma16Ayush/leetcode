/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int j = digits.size() - 1;
        digits[j] += 1;
        ans.push_back(digits[j] % 10 );
        int carry = (digits[j]) / 10;
        j -= 1;
        while(j >= 0)
        {
            // j -= 1;
            digits[j] += carry;
            ans.push_back(digits[j] % 10);
            carry = digits[j] / 10;
            j -= 1;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> ans = {9, 9, 9, 9};
    auto a = Solution().plusOne(ans);
    return 0;
}
