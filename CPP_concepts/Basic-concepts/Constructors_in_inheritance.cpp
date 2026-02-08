#include <iostream>
using namespace std;

class base{
    public:
    int x;

    base(){cout << "default base object constructor created" << endl;}
    base(int x){cout << "parameterized base object constructor created" << endl; this->x = x;}
};

class derived : public base{
    public:
    int y;

    derived(){cout << "default derived object constructor created" << endl;}
    derived(int x, int y):base(x){cout << "parameterized derived object constructor created" << endl; this->y = y;}  // here first parameter will goes to base objects value
              //-------------->
                    //----------------------------------------------------------------------------------------->
};

int main(){

    derived D(5, 10);

    return 0;
}