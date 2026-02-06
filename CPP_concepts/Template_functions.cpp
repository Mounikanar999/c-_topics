#include <iostream>
using namespace std;

template <class T> 
T max(T x, T y){
    return x+y;
}

// int max(int x, int y){
//     return x+y;
// }

int main(){

    int c = max(5, 6);
    cout << c << endl;

    return 0;
}