/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// class Node
// {
// public:
//     string val;
//     vector<Node*> nbs;
//     Node(string _val) : val(_val), nbs(vector<Node*>()){}
// };

class Solution {
public:
    // unordered_map<string, Node*> node_mp;
    // int CalcDistance(string str1, string str2)
    // {
    //     int c = 0;
    //     for(int i = 0; i < str1.size(); i++)
    //         if(str1[i] != str2[i])
    //             c++;
    //     return c;
    // }
    // void ConstructGraph(vector<string>& words)
    // {
    //     for(string str : words)
    //         node_mp[str] = new Node(str);
        
    //     for(int i = 0; i < words.size(); i++)
    //     {
    //         for(int j = i + 1; j < words.size(); j++)
    //         {
    //             if(CalcDistance(words[i], words[j]) == 1)
    //             {
    //                 node_mp[words[i]]->nbs.push_back(node_mp[words[j]]);
    //                 node_mp[words[j]]->nbs.push_back(node_mp[words[i]]);
    //             }
    //         }
    //     }
    // }
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     wordList.push_back(beginWord);
    //     ConstructGraph(wordList);
    //     if(!( node_mp.count(endWord)))
    //         return 0;
        
    //     queue<Node*> q;
    //     q.push(node_mp[beginWord]);
    //     q.push(nullptr);
    //     unordered_set<Node*> visited;
    //     int k = 0;
    //     int found = 0;
    //     while(q.size() > 1)
    //     {
    //         auto front = q.front();
    //         q.pop();
    //         if(front == nullptr)
    //         {
    //             if(q.empty())
    //                 break;
    //             k += 1;
    //             q.push(nullptr);
    //             continue;
    //         }
    //         visited.insert(front);
    //         if(front->val == endWord)
    //         {
    //             found = 1;
    //             break;
    //         }
    //         for(auto nb : front->nbs)
    //             if(!visited.count(nb))
    //                 q.push(nb);
    //     }
    //     return found ? k + 1 : 0;
    // }
    int ladderLength(string st, string en, vector<string>& words)
    {
        unordered_set<string> dict(words.begin(), words.end());
        dict.insert(st);
        if(dict.count(en) == 0)
            return 0;
        queue<string> q;
        q.push(st);
        q.push("");
        int found = 0;
        int k = 0;
        while(q.size() > 1)
        {
            string front = q.front();
            q.pop();
            if(front == "")
            {
                if(q.size() == 0)
                    break;
                k++;
                q.push("");
                continue;
            }
            // visited.insert(front);
            dict.erase(front);
            if(front == en)
            {
                found = 1;
                break;
            }
            for(int i = 0; i < front.size(); i++)
            {
                char temp = front[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    front[i] = c;
                    if(dict.count(front))
                        q.push(front);
                    front[i] = temp;
                }
            }
        }
        return found ? k + 1 : 0;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<string> s = {"hot","dog",};
    cout << Solution().ladderLength("hot", "dog", s);
    return 0;
}