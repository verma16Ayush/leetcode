/** 
 *
 * @author - Ayush
 * @title - longest_palindrominc_substr.cpp
 * @createdOn - 2021-05-18 14:29 Hrs
 * 
 **/
#include <iostream>
#include <bits/stdc++.h>
#define nl '\n'
#define int ll
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
typedef long long ll;
using namespace std;

class Solution {
public:
    int dp[1000][1000];
    int IsPalin(string s, int i, int j)
    {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) dp[i][j] = 1;
        else if(i + 1 == j && s[i] == s[j]) dp[i][j] = 1;
        else if(s[i] == s[j] && IsPalin(s, i + 1, j - 1))
            dp[i][j] = 1;
        else dp[i][j] = 0;
        return dp[i][j];
    }

    string longestPalindrome(string s) 
    {
        // dp = vector<vector<int>>(s.size(), vector<int>(s.length(), -1));
        memset(dp, -1, sizeof(dp));
        IsPalin(s, 0, s.length() - 1);
        int mx = 0;
        int ires = -1;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(IsPalin(s, i, j) && j - i + 1 > mx)
                {
                    mx = j - i + 1;
                    ires = i;
                }
            }
        }
        return s.substr(ires, mx);
    }
};

void PrintMat(vector<vector<int>> a)
{
    for(auto tempvec : a)
    {
        for(auto i : tempvec)
        {
            if(i == -1) cout << "x ";
            else cout << i << " ";
        }
        cout << nl;
    }
}


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    string s = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    cout << sol.longestPalindrome(s) << nl;
    auto stop = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << time.count() << nl;
    // PrintMat(sol.dp);
    return 0;
}