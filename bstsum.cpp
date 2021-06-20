#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    bool Search(Node* root, int target, Node* taken)
    {
        if(!root) return 0;
        if(root->data == target && root != taken) return 1;
        else if(target < root->data) return Search(root->left, target, taken);
        return Search(root->right, target, taken);
    }
    int help(Node* cur, Node* tree, int target)
    {
        if(!cur) return 0;
        if(cur->data <= target)
        {
            if(Search(tree, target - cur->data, cur)) return 1;
            else return help(cur->left, tree, target) || help(cur->right, tree, target);
        }
        return help(cur->left, tree, target);
    }
    int isPairPresent(struct Node *root, int target)
    {
        return help(root, root, target);
    }
};

Node* BuildTree()
{
    int t;
    cin >> t;
    if(t == -1) return nullptr;
    auto root = new Node(t);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Node* root = BuildTree();
    Solution sol;
    cout << sol.isPairPresent(root, 5);
    return 0;
}