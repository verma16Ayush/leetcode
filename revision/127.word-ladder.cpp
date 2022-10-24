/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        dict.insert(beginWord);
        if(dict.count(endWord) == 0)
            return 0;
        queue<string> forw;
        queue<string> back;

        int k = 0;
        forw.push(beginWord);
        forw.push("");

        back.push(endWord);
        back.push("");

        while(forw.size() > 1 && back.size() > 1)
        {
            string frontf = forw.front();
            forw.pop();

            string frontb = back.front();
            back.pop();

            dict.erase(frontf);
            dict.erase(frontb);

            if(frontf == "")
            {
                if(forw.size() == 0)
                    return 0;
                k++;
                forw.push("");
                // continue;
            }

            if(frontb == "")
            {
                if(back.size() == 0)
                    return 0;
                k++;
                back.push("");
            }

            if(frontf != "" && frontf == frontb)
            {
                return k + 1;
            }

            if(frontf != "")
            {
                for(int i = 0; i < frontf.size(); i++)
                {
                    char temp = frontf[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        frontf[i] = c;
                        if(dict.count(frontf))
                            forw.push(frontf);
                        frontf[i] = temp;
                    }
                }
            }
            if(frontb != "")
            {
                for(int i = 0; i < frontb.size(); i++)
                {
                    char temp = frontb[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        frontb[i] = c;
                        if(dict.count(frontb))
                            back.push(frontb);
                        frontb[i] = temp;
                    }
                }
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

    vector<string> vv = {"hot","dot","dog","lot","log","cog"};

    cout << Solution().ladderLength(st, en, vv);
    return 0;
}