#include <bits/stdc++.h>
using namespace std;

// self defined struct to 
// hold the position of snake
struct Pos
{
    int x;
    int y;
    Pos(int _x = 0, int _y = 0)
    {
        this->x = _x;
        this->y = _y;
    }
};

class Snake
{
private:
    int play_width; // right bound
    int play_height; // height bound
    Pos loc; // position of snake's head
    void Invariant()
    {
        assert(loc.x >= 0 && loc.x <= play_width);
        assert(loc.y >= 0 && loc.y <= play_height);
    }
public:
    // initialise the snake object with _width ans _height bounds
    // ans posx, posy current position
    Snake(int _width, int _height, Pos _p)
    {
        this->play_width = _width;
        this->play_height = _height;
        this->loc.x = _p.x;
        this->loc.y = _p.y;
        // call the invariant to ensure the object
        // was constructed correctly
        Invariant();
    }

    // teleport and add inc.x units to current X coordinate
    // ans inc.y units to Y coordinate of snake 
    void TeleportAhead(Pos inc)  
    {
        loc.x += inc.x;
        loc.y += inc.y;
        //ensure that our snake wasn't 
        // teleported out of play bounds
        Invariant();
    }

    // return current position
    // calling invariant is unnecessary
    // because this is an accessor method
    Pos GetLoc()
    {
        return loc;
    }
};



int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    Snake snek(30, 20, Pos(5, 5));

    // will throw assert error because
    // our snake is teleported out of bound
    // snek.TeleportAhead(Pos(40, 40));

    // will also fail Invariant() assertion
    // because the snake is being spawned out
    // of bounds
    // Snake snek2(10, 10, Pos(12, 8));
    return 0;
}