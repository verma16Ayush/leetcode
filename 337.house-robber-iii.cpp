/*
@lc app=leetcode id=337 lang=cpp
 *
[337] House Robber III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct helper
{
	int inc, exc;
	helper(int i = 0, int e = 0)
	{
		inc = i;
		exc = e;
	}
};

class Solution {
public:
	helper MaxRob(TreeNode* root)
	{
		helper res;
		if(!root) return res = helper();
		helper left = MaxRob(root->left);
		helper right = MaxRob(root->right);
		res.inc = root->val + left.exc + right.exc;
		res.exc = max(left.exc, left.inc) + max(right.exc, right.inc);
		return res;
	}
	int rob(TreeNode* root) 
	{
		if(!root) return 0;
		auto res = MaxRob(root);
		return max(res.inc, res.exc);
	}
};
// @lc code=end

TreeNode* BuildTree()
{
	int t;
	cin >> t;
	if(t == -1) return nullptr;
	TreeNode* root = new TreeNode(t);
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
	TreeNode* root = BuildTree();
	Solution sol;
	cout << sol.rob(root) << endl;
	return 0;
}