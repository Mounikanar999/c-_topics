#include <iostream>
using namespace std;
// static int a = 0;

auto max(auto x, auto y){
    // static int a = 1;
    // cout << a << endl;
    x++, y++; 
    cout << "x and y: " << x << " " << y << endl;
    return x>y ? x : y;
}

auto min(auto x, auto y){
    // static int a = 1;
    // cout << a << endl;
    return x>y ? x : y;
}

int main(){

    cout << "max: " << max(1,6) << endl;
    cout << "min: " << min(1,6) << endl;

    return 0;
}