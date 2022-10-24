/*
@lc app=leetcode id=208 lang=cpp
 *
[208] Implement Trie (Prefix Tree)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class TrieNode {
public:
    char val;
    int is_terminal;
    unordered_map<char, TrieNode*> chldr;
    TrieNode(char _val, int _is_terminal) : val(_val), is_terminal(_is_terminal), chldr(unordered_map<char, TrieNode*>()) {}
    TrieNode(char _val) : val(_val), is_terminal(0), chldr(unordered_map<char, TrieNode*>()){}
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        TrieNode* curr = this->root;
        int i = 0;
        for(i; i < word.length(); i++) 
        {
            if(curr->chldr.count(word[i]))
                curr = curr->chldr[word[i]];
            else
            {
                TrieNode* newNode = new TrieNode(word[i]);
                curr->chldr[word[i]] = newNode;
                curr = curr->chldr[word[i]];
            }
        }
        curr->is_terminal = 1;
    }

    bool search(string word) {
        TrieNode* curr = this->root;
        int i = 0;
        for(i; i < word.length(); i++)
        {
            if(curr->chldr.count(word[i]))
                curr = curr->chldr[word[i]];
            else
                break;
        }
        return i == word.length() && curr->is_terminal;
    }
    
    bool startsWith(string word) {
        TrieNode* curr = this->root;
        int i = 0;
        for(i; i < word.length(); i++)
        {
            if(curr->chldr.count(word[i]))
                curr = curr->chldr[word[i]];
            else
                break;
        }
        return i == word.length();
    }
};

/**
Your Trie object will be instantiated and called as such:
 */
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_1 = obj->search("app");
    bool param_3 = obj->startsWith("app");
    obj->insert("app");
    bool param_4 = obj->search("app");

    
    return 0;
}
