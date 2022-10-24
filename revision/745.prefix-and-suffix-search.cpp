/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class TrieNode {
public:
    char val;
    int wt;
    unordered_map<char, TrieNode*> chldr;
    TrieNode(char _val, int _wt) : 
        val(_val), wt(_wt), chldr(unordered_map<char, TrieNode*>()) {}
};

class Trie {
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode('\0', -1);
    }

    void Insert(string word, int _wt)
    {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!cur->chldr.count(word[i]))
                cur->chldr[word[i]] = new TrieNode(word[i], _wt);
            cur = cur->chldr[word[i]];
        }
    }

    int Search(string pref)
    {
        TrieNode* cur = root;
        int i = 0;
        for(i; i < pref.size(); i++)
        {
            if(cur->chldr.count(pref[i]))
                cur = cur->chldr[pref[i]];
            else
                break;
        }
        return i == pref.size() ? cur->wt : -1; 
    }
};
class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {
        trie = *new Trie();
        for(int i = 0; i < words.size(); i++)
        {
            string insertable = words[i] + '{' + words[i];
            for(int j = 0; j <= words[i].length(); j++)
                trie.Insert(insertable.substr(j), i);
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.Search(suffix + '{' + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}
