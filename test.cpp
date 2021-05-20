#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir;
    bool dfs(vector<vector<char>>& board, int i, int j, string w, int m)
    {
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0) return false; 
        if(m == w.length()) return true;
        if(board[i][j] == w[m])
        {
            for(auto d : dir)
            {
                if(dfs(board, i + d.first, j + d.second, w, m + 1)) return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool res = false;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0]) res = res || dfs(board, i, j, word, 0); 
            }
        }
        return res;
    }
};
/** 
 *
 * @author - Ayush
 * @title - test.cpp
 * @createdOn - 2021-05-20 16:16 Hrs
 * 
 **/

#define nl '\n'
#define int ll
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
using namespace std;
typedef long long ll;

ll PowModulo(ll a, ll b)
{
    ll res = 1;
    a = a % MOD;
    if(b == 0) return 1;
    if(a == 0) return 0;
    while(b)
    {
        if(b & 1) res = (res * a) % MOD;
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return res;
}

vector<int> PrefixSum(const vector<int>& a)
{
    vector<int> ps(a.size() + 1);
    ps[0] = 0;
    for(int i = 1; i <= a.size(); i++)
    {
        ps[i] = a[i - 1];
        ps[i] += ps[i - 1];
    }
    return ps;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    vector<vector<char>> a;
    for(auto& tem : a)
    {
        for(char& c : tem) cin >> c;
    }

    Solution sol;
    cout << sol.exist(a, "ABCB") << nl;
    return 0;
}