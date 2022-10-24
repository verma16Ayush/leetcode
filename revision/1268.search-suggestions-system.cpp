/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class TrieNode
{
public:
    char val;
    unordered_map<char, TrieNode*> chldr;
    int is_terminal;
    TrieNode(char _val) : 
        val(_val), is_terminal(0), chldr(unordered_map<char, TrieNode*>()) {}
    TrieNode(char _val, int _is_terminal) : 
        val(_val), is_terminal(_is_terminal), chldr(unordered_map<char, TrieNode*>()) {}
};

class Trie
{
public:
    TrieNode* root;
    vector<string> searchRes;
    Trie() : root(new TrieNode('\0')) {}
    
    void Insert(string word)
    {
        TrieNode* curr = this->root;
        int i = 0;
        for(int i = 0; i < word.length(); i++)
        {
            if(curr->chldr.count(word[i]))
                curr = curr->chldr[word[i]];
            else
            {
                curr->chldr[word[i]] = new TrieNode(word[i]);
                curr = curr->chldr[word[i]];
            }
        }
        curr->is_terminal = 1;
    }

    void DfsSearch(TrieNode* curr, string word)
    {
        if(curr->is_terminal)
            searchRes.push_back(word);
        
    }
    vector<string> GetMatches(string prefix)
    {
        searchRes = vector<string>();
        TrieNode* curr = this->root;
        int i = 0;
        for(i; i < prefix.length(); i++)
        {
            if(curr->chldr.count(prefix[i]))
                curr = curr->chldr[prefix[i]];
            else 
                break;
        }
        if(i != prefix.length())
            return {};
        return {};
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string pref = "";
        vector<vector<string>> ans;
        for(char c : searchWord)
        {
            pref += c;
            vector<string> temp;
            int i = lower_bound(products.begin(), products.end(), pref) - products.begin();
            for(int k = i; k < i + 3 && k < products.size(); k++)
            {
                if(products[k].find(pref) == string::npos)
                    break;
                temp.push_back(products[k]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

