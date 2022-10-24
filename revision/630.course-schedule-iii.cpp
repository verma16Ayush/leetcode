/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int>& a, vector<int>& b)-> bool {
            return a[1] < b[1];
        });
        priority_queue<int, vector<int>> pq;
        int time = 0;
        int c = 0;
        for(auto& i: courses)
        {
            time += i[0];
            pq.push(i[0]);
            c += 1;
            if(time > i[1])
            {
                time -= pq.top();
                pq.pop();
                c -= 1;
            }
        }
        return pq.size();
        // if(courses.size() <= 0) return 0;
        // sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
        //     return a[1] < b[1];
        // });
        // priority_queue<int> q;
        // int sum = 0;
        // for(auto i : courses) {
        //     sum += i[0];
        //     q.push(i[0]);
        //     if(sum > i[1]) {
        //         sum -= q.top();
        //         q.pop();
        //     }
        // }
        // return q.size();
    }
};
// @lc code=end

