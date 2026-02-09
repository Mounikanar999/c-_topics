#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){

    vector<string> vect;

    cout << vect.size() << endl;
    cout << vect.capacity() << endl;

    vect.reserve(10);

    cout << vect.size() << endl;
    cout << vect.capacity() << endl;

    vector<string>::iterator i;
    for(i=vect.begin(); i!=vect.end(); i++){
        *i = "sangi";
    }
    vect.push_back("roopa");
    vect.pop_back();

    vect.insert(vect.end(), "roopa");
    vect.erase(vect.begin());

    cout << vect.front() << endl;
    cout << vect.back() << endl;

    vector<string>::reverse_iterator it;
    for(it=vect.rbegin(); it!=vect.rend(); it++){
        cout << *it << endl;
    }

    return 0;
}