#include <iostream>
using namespace std;

auto max(auto x, auto y){
    return x>y ? x : y;
}

auto min(auto x, auto y){
    return x<y ? x : y;
}

int main(){

    int (*fptr)(int, int);

    fptr = max;

    cout << (*fptr)(1, 6) << endl;

    fptr = min;

    cout << (*fptr)(1, 6) << endl;

    return 0;
}