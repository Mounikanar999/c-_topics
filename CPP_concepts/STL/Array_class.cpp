#include <iostream>
#include <array>
#include <string>
using namespace std;

int main(){

    array<string, 10> array_ = {"sangi", "roopa", "santhu", "laxmi"};

    cout << array_.size() << endl;
    cout << array_.max_size() << endl;

    for(int i=0; i<10; i++){
        if(array_[i].empty()){
            array_[i] = "dad";
        }
    }

    array<string, 10>::iterator sangi;
    for(sangi=array_.begin(); sangi!=array_.end(); sangi++){
        cout << *sangi << endl;
    }

    return 0;
}