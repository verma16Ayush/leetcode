/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> threeSum(vector<int>& nums)
    // {
    //     if(nums.empty()) return vector<vector<int>>();
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> ans;
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         int a = i + 1;
    //         int b = nums.size() - 1;
    //         while(a < b && a < nums.size() - 1)
    //         {
    //             if(nums[i] + nums[a] + nums[b] == 0)
    //             {
    //                 ans.push_back({nums[i], nums[a], nums[b]});
    //                 while(a < nums.size() && nums[a] == ans.back()[1]) a++;
    //                 while(b >= 0 &&  nums[b] == ans.back()[2])b--;
    //             }

    //             else if(a < nums.size() && b >= 0 && nums[i] + nums[a] + nums[b] > 0) b--;
    //             else if(a < nums.size() && b >= 0 && nums[i] + nums[a] + nums[b] < 0) a++;
    //         }
    //         if(ans.size()) while(nums[i + 1] == ans.back()[0] && i + 1 < nums.size()) i++;
    //     }

    //     return ans;
    // }
    vector<vector<int>> threeSum(vector<int> &num)
    {

        vector<vector<int>> res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++)
        {

            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back)
            {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else
                {
                    vector<int> triplet = {num[i], num[front], num[back]};
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1])
                        front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2])
                        back--;
                }
            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return res;
    }
};
// @lc code=end
