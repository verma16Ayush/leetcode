/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<string> hash;

    bool HashCheck(vector<int> temp)
    {
        string checksum = "";
        for(int i : temp) checksum += (char)(10 + i);
        if(hash.find(checksum) == hash.end())
        {
            hash.insert(checksum);
            return false;
        }
        return true;
    }

    bool WasUsed(vector<int>& index, int i)
    {
        return index[i];
    }

    void Helper(vector<int>& a, vector<int> temp, vector<int> used_index)
    {
        if(temp.size() == a.size())
        {
            if(!HashCheck(temp)) ans.push_back(temp);
            return;
        }

        for(int i = 0; i < a.size(); i++)
        {
            if(!WasUsed(used_index, i))
            {
                temp.push_back(a[i]);
                used_index[i] = 1;
                Helper(a, temp, used_index);
                temp.pop_back();
                used_index[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        ans = vector<vector<int>>();
        hash = unordered_set<string>();
        Helper(nums, vector<int>(), vector<int>(nums.size(), 0));
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
    Solution sol;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    auto start = chrono::high_resolution_clock::now();
    sol.permuteUnique(a);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << endl;
    return 0;
}
