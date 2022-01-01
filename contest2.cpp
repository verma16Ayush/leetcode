#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubSeg(vector<int> a, int k)
    {
        int n = a.size();
        int cnt0 = 0;
        int l = 0;
        int max_len = 0;
    
        // i decides current ending point
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                cnt0++;
    
            // If there are more 0's move
            // left point for current ending
            // point.
            while (cnt0 > k) {
                if (a[l] == 0)
                    cnt0--;
                l++;
            }
    
            max_len = max(max_len, i - l + 1);
        }
    
        return max_len;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> a(answerKey.size(), 1);
        vector<int> b(answerKey.size(), 1);
        for(int i = 0; i < answerKey.size(); i++)   
        {
            if(answerKey[i] == 'T')
            {
                b[i] = 0;
            }
            else
            {
                a[i] = 0;
            }
        }

        return max(longestSubSeg(a, k), longestSubSeg(b, k));

    }
};
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}