#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* LevelBuildTree()
{
    queue<TreeNode*> q;
    int r;
    cin >> r;
    if(r == -1)
        return nullptr;
    auto root = new TreeNode(r);
    q.push(root);
    while(q.size())
    {
        auto front = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;

        if(l != -1)
        {
            front->left = new TreeNode(l);
            q.push(front->left);
        }

        if(r != -1)
        {
            front->right = new TreeNode(r);
            q.push(front->right);
        }
    }
    return root;
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout << "hello" << endl;
    auto root = LevelBuildTree();
    return 0;
}