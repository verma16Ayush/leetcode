/** 
 *
 * @author - Ayush
 * @title - level_order.cpp
 * @createdOn - 2021-03-24 15:10 Hrs
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree()
{
    int n;
    cin >> n;
    TreeNode* root = new TreeNode();
    if(n == -1) return nullptr;
    else
    {
        root->val = n;
        root->left = buildTree();
        root->right = buildTree();
    }
    return root;
}
vector<int> inorder;
void GetInorder(TreeNode* root)
{
    if(root == nullptr) return;
    GetInorder(root->left);
    inorder.push_back(root->val);
    GetInorder(root->right);
}

vector<int> preorder;
void GetPreorder(TreeNode* root)
{
    if(root == nullptr) return;
    preorder.push_back(root->val);
    GetPreorder(root->left);
    GetPreorder(root->right);
}

class Solution {
public:
    pair<int, int> p;
    int kthSmallest(TreeNode* root, int k) 
    {
        static int count = 0;
        p.first = 0;
        p.second = 0;
        BuildInorder(root, k);
        return p.first;
    }
private:
    void BuildInorder(TreeNode* root, int k)
    {

        if(!root) return;
        // if(p.second == k) return;
        BuildInorder(root->left, k);
        if(p.second == k) return;
        p.first = root->val;
        p.second += 1;
        BuildInorder(root->right, k);
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    auto root = buildTree();
    Solution sol;
    cout << sol.kthSmallest(root, 1) << nl;
    return 0;
}