/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct Node
{
    string w;
    vector<Node*> nbs;
    Node() : w(string()), nbs(vector<Node*>()) {}
    Node(string _w) : w(_w), nbs(vector<Node*>()) {}
};
class Solution {
private:
    unordered_map<string, Node*> mp;
    unordered_set<Node*> vis;
    vector<vector<string>> ans;
    vector<string> temp;

    int calcDist(string a, string b)
    {
        if(a.size() != b.size()) return -1;
        int i = 0;
        int c = 0;
        for(int i = 0; i < a.length(); i++)
            c += a[i] != b[i];
        return c;
    }

    void BuildGraph(vector<string>& wordls)
    {
        for(auto word : wordls)
            if(mp.find(word) == mp.end())
                mp[word] = new Node(word);

        for(int i = 0; i < wordls.size(); i++)
            for(int j = 0; j < wordls.size(); j++)
                if(i != j && calcDist(wordls[i], wordls[j]) == 1)
                    mp[wordls[i]]->nbs.push_back(mp[wordls[j]]);
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        BuildGraph(wordList);
        
    }
};
// @lc code=end

