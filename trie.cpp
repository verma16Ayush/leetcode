#include <bits/stdc++.h>
struct Node;
typedef std::unordered_map<char, Node*> hashmap;
using namespace std;

struct Node
{
    char c;
    hashmap hm;
    int isTerminal;
    Node(char c = '\0')
    {
        this->c = c;
        isTerminal = 0;
    }
};

class Trie {
private:
    /** Initialize your data structure here. */
    Node* root;
    
public:
    Trie() 
    {
        root = new Node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Node* cur = root;
        int i = 0;
        while(cur->hm.find(word[i]) != cur->hm.end() && cur->hm[word[i]])
        {
            cur = cur->hm.find(word[i])->second;
            i++;
        }
        while(i != word.length())
        {
            Node* newNode = new Node(word[i]);
            cur->hm[word[i]] = newNode;
            cur = cur->hm[word[i]];
            i++;
        }
        cur->isTerminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Node* cur = root;
        int i = 0;
        while(cur && cur->hm.find(word[i]) != cur->hm.end())
        {
            cur = cur->hm[word[i]];
            i++;
        }
        return i == word.length() && cur->isTerminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Node* cur = root;
        int i = 0;
        while(i < prefix.length() && cur->hm.find(prefix[i]) != cur->hm.end())
        {
            cur = cur->hm[prefix[i]];
            i++;
        }
        return i == prefix.length();
    }
};

int main()
{
    Trie* trie = new Trie();
    trie->insert("ayush");
    trie->insert("apple");
    trie->insert("app");
    int k = trie->search("app");
    k = trie->search("ap");
    k = trie->search("ayush");
    k = trie->startsWith("ayu");
    k = trie->startsWith("apu");
    return 0;
}