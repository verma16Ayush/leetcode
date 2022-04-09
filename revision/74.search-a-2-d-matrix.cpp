/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int GetAt(const vector<vector<int>>& mat, int i)
    {
        int r = mat.size();
        int c = mat[0].size();
        return mat[i / c][i % c];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int st = 0;
        int en = r * c - 1;
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            if(GetAt(matrix, mid) == target)
                return true;
            else if(GetAt(matrix, mid) < target)
                st = mid + 1;
            else
                en = mid - 1;
        }
        return false;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> a = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout << Solution().searchMatrix(a, 7);
    return 0;
}