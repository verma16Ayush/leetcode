/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct TrieNode;
typedef unordered_map<char, TrieNode*> hash_map;
struct TrieNode
{
    char startsWith;
    hash_map next_list;
    int is_terminal;
    TrieNode(char c = '\0')
    {
        this->startsWith = c;
        is_terminal = 0;
    }
};

class Trie {

private:
    TrieNode* node;
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        node = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* cur = this->node;
        for(int i = 0; i < word.length(); i++)
        {
            if(cur->next_list.find(word[i]) != cur->next_list.end()) cur = cur->next_list[word[i]];
            else 
            {
                cur->next_list[word[i]] = new TrieNode(word[i]);
                cur = cur->next_list[word[i]];
            }
        }
        cur->is_terminal = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* cur = this->node;
        for(int i = 0; i < word.length(); i++)
        {
            if(cur->next_list.find(word[i]) == cur->next_list.end()) return false;
            else cur = cur->next_list[word[i]];
        }
        return cur->is_terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) 
    {
        TrieNode* cur = this->node;
        for(int i = 0; i < word.length(); i++)
        {
            if(cur->next_list.find(word[i]) == cur->next_list.end()) return false;
            else cur = cur->next_list[word[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

