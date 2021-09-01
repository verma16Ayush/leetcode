/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// struct Node
// {
//     string w;
//     vector<Node*> nbs;
//     Node() : w(string()), nbs(vector<Node*>()) {}
//     Node(string _w) : w(_w), nbs(vector<Node*>()) {}
// };

// int calcDist(string a, string b)
// {
//     if(a.size() != b.size()) return -1;
//     int i = 0;
//     int c = 0;
//     for(int i = 0; i < a.length(); i++)
//         c += a[i] != b[i];
//     return c;
// }

// class Solution {
// public:
//     unordered_map<string, Node*> mp;

//     void BuildGraph(vector<string>& wordls)

//     {
//         for(auto word : wordls)
//             if(mp.find(word) == mp.end())
//                 mp[word] = new Node(word);

//         for(int i = 0; i < wordls.size(); i++)
//             for(int j = 0; j < wordls.size(); j++)
//                 if(i != j && calcDist(wordls[i], wordls[j]) == 1)
//                     mp[wordls[i]]->nbs.push_back(mp[wordls[j]]);
//     }

//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
//     {
//         if(beginWord.size() != endWord.size()) return 0;
//         BuildGraph(wordList);
//         if(mp.find(endWord) == mp.end()) return 0;
//         if(mp.find(beginWord) == mp.end())
//         {
//             mp[beginWord] = new Node(beginWord);
//             for(string w : wordList)
//                 if(calcDist(beginWord, w) == 1)
//                     mp[beginWord]->nbs.push_back(mp[w]);
//         }   
//         queue<Node*> q;
//         q.push(mp[beginWord]);
//         q.push(nullptr);
//         int k = 0;
//         unordered_set<Node*> vis;
//         while(q.size())
//         {
//             auto front = q.front();
//             q.pop();
//             if(front != nullptr) vis.insert(front);
//             if(front == nullptr)
//             {
//                 k += 1;
//                 if(q.empty()) return 0;
//                 q.push(nullptr);
//                 continue;
//             }
//             for(auto node : front->nbs)
//             {
//                 if(vis.find(node) != vis.end()) continue;
//                 if(node->w == endWord) return k + 2;
//                 q.push(node);
//             }
//         }
//         return 0;
//     }

// };
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> ls;
        for(string s : wordList) ls.insert(s);
        if(ls.find(endWord) == ls.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        q.push("");
        int k = 1;
        unordered_set<string> vis;
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            vis.insert(front);
            // if(front == endWord) return k;
            if(front == "")
            {
                if(q.empty()) return 0;
                q.push("");
                k += 1;
                continue;
            }
            for(int i = 0; i < front.size(); i++)
            {
                char temp = front[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    front[i] = c;
                    if(vis.find(front) == vis.end() && ls.find(front) != ls.end())
                    {
                        if(front == endWord) return k + 1;
                        q.push(front);
                    }
                }
                front[i] = temp;
            }
        }
        return 0;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string st = "hit";
    string en = "cog";
    vector<string> ls = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(st, en, ls);
    return 0;
}