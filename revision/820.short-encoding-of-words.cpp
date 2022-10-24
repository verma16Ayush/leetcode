/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class TrieNode {
public:
    char val;
    unordered_map<char, TrieNode*> chldr;
    TrieNode(char _val) : val(_val), chldr(unordered_map<char, TrieNode*>()) {}
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(string& word: words)
            reverse(word.begin(), word.end());

        unordered_set<string> wordset(words.begin(), words.end());
        vector<pair<TrieNode*, int>> leaves;

        TrieNode* root = new TrieNode('\0');
        for(string word : wordset)
        {
            TrieNode* cur = root;
            for(int i = 0; i < word.size(); i++)
            {
                if(!cur->chldr.count(word[i]))
                    cur->chldr[word[i]] = new TrieNode(word[i]);
                cur = cur->chldr[word[i]];
            }
            leaves.push_back({cur, word.length() + 1});
        }
        int ans = 0;
        for(auto& p : leaves)
            if(p.first->chldr.size() == 0)
                ans += p.second;
        return ans;
    }
};
// @lc code=end

