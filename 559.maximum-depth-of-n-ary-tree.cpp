/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
// @lc code=start

class Solution {
public:
	int maxDepth(Node* root) {
		if(!root) return 0;
		queue<Node*> q;
		q.push(root);
		q.push(nullptr);
		int k = 0;
		while(q.size())
		{
			auto front = q.front();
			q.pop();
			if(front == nullptr)
			{
				k += 1;
				if(q.empty()) return k;
				q.push(nullptr);
				continue;
			}
			for(auto child : front->children)
				q.push(child);
		}
		return k;
	}
};
// @lc code=end

