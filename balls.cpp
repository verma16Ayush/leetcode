#include <bits/stdc++.h>
using namespace std;
class balls{
public:
    int a;
    balls() : a(0){}
    virtual void printme()
    {
        cout << "I AM BASE" << endl;
    }
};

class der : public balls {
public:
    void printme() override {
        cout << "I AM DERIVED" << endl;
    }
};

void PrintSome(balls* b)
{
    b->printme();
}

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    der* a = new der();
    PrintSome(a);
    return 0;
}