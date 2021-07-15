/** 
 *
 * @author - Ayush
 * @title - bestcust.cpp
 * @createdOn - 2021-07-09 21:55 Hrs
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

struct customer
{
    int is_best;
    string id;
    ld income;
    ld spend;
    ld dist;

    customer(string id = "", ld income = 0.0f, ld spend = 0.0f, int is_best = 0)
    {
        this->id = id;
        this->income = income;
        this->spend = spend;
        this->is_best = is_best;
        this->dist = sqrt(pow(this->income, 2) + pow(this->spend, 2));
    }
};

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

vector<customer*> mergeArrays(vector<customer*>& arr1, vector<customer*>& arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0, k = 0;
    vector<customer*> arr3(arr1.size() + arr2.size());
    while (i<n1 && j <n2)
    {
        if (arr1[i]->dist < arr2[j]->dist)
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
    return arr3;
}

int getNeighbor(vector<customer*>& a, int in)
{
    int l = -1, r = -1;
    int i = in + 1;
    while(i < a.size()) 
    {
        if(a[i]->is_best) 
        {
            l = i;
            break;
        }
        i++;
    }
    int j = in - 1;
    while(j >= 0)
    {
        if(a[j]->is_best)
        {
            r = j;
            break;
        }
        j--;
    }

    if(i == -1 || j == -1)
    {
        return i == -1 ? j : i;
    }
    return min(l, r, [&](int l, int r)->bool{
        int d1 = abs(a[l]->dist - a[in]->dist);
        int d2 = abs(a[r]->dist - a[in]->dist);
        return d1 < d2;
    });
}

void GetInp(string& id, ld& income, ld& spend)
{
    string str;
    cin.ignore();
    getline(cin, str);
    vector<string> ans;
    string temp = "";
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            ans.push_back(temp);
            temp = "";
            continue;
        }
        temp += str[i];
    }
    ans.push_back(temp);
    if(ans.size() != 3) return;
    else 
    {
        id = ans[0];
        try
        {
            income = stold(ans[1]);
        }
        catch(const std::exception& e)
        {
            return;
        }
        
        try
        {
            spend = stold(ans[2]);
        }
        catch(const std::exception& r)
        {
            return;
        }
    }
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO
    int n;
    cin >> n;
    vector<customer*> best;
    best.reserve(n);

    string id;
    ld income;
    ld spend;

    for(int i = 0; i < n; i++)
    {
        id = "";
        income = -1.0f;
        spend = -1.0f;
        GetInp(id, income, spend);
        if(id == "" || income < 0 || spend < 0) continue;
        best.push_back(new customer(id, income, spend, 1));
    }

    int m;
    cin >> m;
    vector<customer*> uni;
    uni.reserve(m);
    
    for(int i = 0; i < m; i++)
    {
        id = "";
        income = -1.0f;
        spend = -1.0f;
        GetInp(id, income, spend);
        if(id == "" || income < 0 || spend < 0) continue;
        uni.push_back(new customer(id, income, spend,0));
    }

    sort(best.begin(), best.end(), [&](const customer* a, const customer* b) -> bool{
        return a->dist < b->dist;
    });

    // sort(uni.begin(), uni.end(), [&](const customer* a, const customer* b) -> bool{
    //     return a->dist < b->dist;
    // });

    vector<customer*> merged = mergeArrays(best, uni);
    // unordered_map<string, customer*> mp;
    // for(int i = 0; i < merged.size(); i++)
    // {
    //     mp[merged[i]->id] = merged[i];
    // }

    vector<customer*> ans;
    for(int i = 0; i < uni.size(); i++)
    {
        int k = lower_bound(best.begin(), best.end(), uni[i], [&](const customer* a, const customer* b)->bool{
            return a->dist < b->dist;
        }) - best.begin();

        k = min(k, (int)best.size() - 1);
        ld d = abs(best[k]->dist - uni[i]->dist);

        int l  = -1;
        if(k == 0) l = 1;
        else if(k == best.size() - 1) l = best.size() - 2;
        else l = min(k - 1, k + 1, [&](const int a, const int b)->bool{
            return abs(best[a]->dist - best[k]->dist) < abs(best[b]->dist - best[k]->dist);
        });
        ld D = abs(best[l]->dist - best[k]->dist);

        if(d / D < 1e6) ans.push_back(uni[i]);
    }

    sort(ans.begin(), ans.end(), [&](const customer* a, const customer* b)->bool{
        return a->id < b->id;
    });

    for(auto i : ans)
    {
        cout << i->id << nl;
    }

    return 0;
}