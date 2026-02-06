#include <iostream>
using namespace std;

int count = 0;

void reccursive_function(int a){
    if(a<0){
        return;
    }else{
        cout << "calling inner function calls" << " " << count << endl;
        count++;
        reccursive_function(a-1);
    }
    cout << "calling outer function calls" << " " << count << endl;
    count--;
}

int main(){

    reccursive_function(10);

    return 0;
}