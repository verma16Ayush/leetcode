/** 
 *
 * @author - Ayush
 * @title - hellodsd.cpp
 * @createdOn - 2022-02-07 11:47 Hrs
 * 
 **/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> my_merge(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> merged;
    while(i < a.size() && j < b.size())
    {
        if(a[i] > b[i])
            merged.push_back(a[i++]);
        else
            merged.push_back(b[j++]);
    }

    while(i < a.size())
        merged.push_back(a[i++]);
    
    while(j < b.size())
        merged.push_back(b[j++]);
    
    return merged;
}


int main()
{
    string str1, str2;
    int num;
    cin >> str1;
    cin >> str2;
    cin >> num;
    vector<int> a, b;
 
    // Get the string to be taken
    // as input in stringstream
    stringstream ss1(str1);
    stringstream ss2(str2);
 
    // Parse the string
    for (int i; ss1 >> i;) {
        a.push_back(i);
        if (ss1.peek() == ',')
            ss1.ignore();
    }

    for(int i; ss2 >> i;) {
        b.push_back(i);
        if(ss2.peek() == ',')
            ss2.ignore();
    }

    vector<int> ans = my_merge(a, b);
    string out = "";
    for(int i = 0; i < num; i++){
        out.push_back('0' + (ans[i]));
        out.push_back(',');
    }

    out.pop_back();
    cout << out << endl;
    return 0;
}