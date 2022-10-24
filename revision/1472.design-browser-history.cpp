/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct BrowserNode {
    string url;
    BrowserNode* next;
    BrowserNode* prev;
    BrowserNode(string _url)
    {
        this->url = _url;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class BrowserHistory {
public:
    BrowserNode* history;
    BrowserNode* currentPage;
    BrowserHistory(string homepage) {
        history = new BrowserNode(homepage);
        currentPage = history;
    }
    
    void visit(string url) {
        this->currentPage->next = new BrowserNode(url);
        BrowserNode* temp = this->currentPage;
        this->currentPage = this->currentPage->next;
        this->currentPage->prev = temp;
    }
    
    string back(int steps) {
        while(steps && this->currentPage->prev)
        {
            steps--;
            this->currentPage = this->currentPage->prev;
        }

        return this->currentPage->url;
    }
    
    string forward(int steps) {
        while(steps && this->currentPage->next)
        {
            steps--;
            this->currentPage = this->currentPage->next;
        }
        return this->currentPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

