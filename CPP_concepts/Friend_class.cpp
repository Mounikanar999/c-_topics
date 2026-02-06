#include <iostream>
using namespace std;

// void friend_function();

class first{
    private:
    int x;

    first(){cout << "default first object constructor created" << endl;}
    first(int x){cout << "parameterized first object constructor created" << endl; this->x = x;}

    // friend void friend_function(base c);
    friend second;
};

// void friend_function(base C){cout << "value of x: " << C.x << endl;}

class second{
    public:
    int y;
    first F;

    second(){cout << "default second object constructor created" << endl;}
    second(int y){cout << "parameterized second object constructor created" << endl; this->y = y;} 

    // void func(){first F; /* F.x = 15; */ cout << "value of x from second class object: " << F.x << endl;}
    void func(){cout << "value of x from second object: " << F.x << endl;}
};

int main(){

    // derived D(5, 10);

    // friend_function(D);

    second S(10);
    S.func();

    return 0;
}