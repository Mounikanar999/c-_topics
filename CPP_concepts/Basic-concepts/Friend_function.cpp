#include <iostream>
using namespace std;

// void friend_function();

class base{
    public:
    int x;

    base(){cout << "default base object constructor created" << endl;}
    base(int x){cout << "parameterized base object constructor created" << endl; this->x = x;}

    friend void friend_function(base c);
};

void friend_function(base C){cout << "value of x: " << C.x << endl;}

class derived : public base{
    public:
    int y;

    derived(){cout << "default derived object constructor created" << endl;}
    derived(int x, int y):base(x){cout << "parameterized derived object constructor created" << endl; this->y = y;} 
};

int main(){

    derived D(5, 10);

    friend_function(D);

    return 0;
}