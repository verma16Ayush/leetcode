/** 
 *
 * @author - Ayush
 * @title - palindrome_linked_list.cpp
 * @createdOn - 2021-04-01 22:56 Hrs
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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* BuildList(vector<int>& a)
{
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for(int i : a)
    {
        ListNode* newNode = new ListNode(i);
        cur->next = newNode;
        cur = cur->next;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        int i = 0;
        ListNode* cur = head;
        ListNode* fastp = head;
        ListNode* slowp = head;
        while(fastp && fastp->next)
        {
            i += 1;
            slowp = slowp->next;
            fastp = fastp->next->next;
        }

        if(fastp) slowp = slowp->next;
        stack<int> st;
        while(slowp)
        {
            st.push(slowp->val);
        }
        while(cur && !st.empty())
        {
            if(cur->val != st.top()) return false;
            cur = cur->next;
            st.pop();
        }
        return true;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a)
    {
        cin >> i;
    }
    ListNode* head = BuildList(a);
    Solution* sol = new Solution();
    int res = sol->isPalindrome(head);
    getchar();
    return 0;
}