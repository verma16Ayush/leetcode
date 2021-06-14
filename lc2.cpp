#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> row;
    vector<vector<int>> col;
    bool fun(vector<vector<int>> arr, int a,int b, int s)
    {
        bool ans=true;
        int x = b-1>=0?row[a][b-1]:0;
        int sum = row[a][b+s] - x;
        for (int i = a; i <=a+s ; i++) {
            x = b-1>=0?row[i][b-1]:0;
            if(sum!=row[i][b+s] - x) {
                return false;
            }
        }

        for (int j = b; j <=b+s ; j++) {
            x = a-1>=0?col[a-1][j]:0;
            if(sum!=col[a+s][j] - x)
                return false;
        }
        int sum1=0,sum2=0;
        for (int i = 0; i <=s ; i++) {
            sum1+=arr[a+i][b+i];
            sum2+=arr[a+i][b+s-i];
        }
        if(sum1==sum2 && sum1==sum)
            return true;
        else
            return false;

    }

    int largestMagicSquare(vector<vector<int>>& arr) {
        int n= arr.size();
        int m= arr[0].size();
        row = vector<vector<int>>(n, vector<int>(m, 0));
        col = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            row[i][0]=arr[i][0];
            for (int j = 1; j < m; j++) {
                row[i][j] = row[i][j-1]+arr[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            col[0][j]=arr[0][j];
            for (int i = 1; i < n; i++) {
                col[i][j] = col[i-1][j]+arr[i][j];
            }
        }
        int mx=1;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m-1; j++) {
                
                int s = min(n-i-1,m-j-1);
                while(i+s<n&&j+s<m)
                {
                    if(s<1)
                        break;
                    bool ans = fun(arr,i,j,s);
                    if(ans)
                    {

                        mx = max(s+1, mx);
                        break;
                    }
                    else
                        --s;
                }
            }
        }
        return mx;
    }

};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    Solution sol;
    cout << sol.largestMagicSquare(a);
    return 0;
}
