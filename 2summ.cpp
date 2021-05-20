#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.empty()) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int a = i + 1;
            int b = nums.size() - 1;
            while(a < b && a < nums.size() - 1)
            {
                if(nums[i] + nums[a] + nums[b] == 0)
                {
                    ans.push_back({nums[i], nums[a], nums[b]});
                    while(a < nums.size() && nums[a] == ans.back()[1]) a++;
                    while(b >= 0 &&  nums[b] == ans.back()[2])b--;
                }

                else if(a < nums.size() && b >= 0 && nums[i] + nums[a] + nums[b] > 0) b--;
                else if(a < nums.size() && b >= 0 && nums[i] + nums[a] + nums[b] < 0) a++;
            }
            if(ans.size()) while(nums[i + 1] == ans.back()[0] && i + 1 < nums.size()) i++;
        }

        return ans;
    }
};

void PrintArray(vector<int> a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    Solution* sol = new Solution();
    vector<vector<int> > ans = sol->threeSum(a);
    for(auto i : ans) PrintArray(i);
    return 0;

}