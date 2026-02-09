#include <iostream>
#include <thread>
#include <chrono>

typedef unsigned long long ull;

ull sumEven_ = 0;
ull sumOdd_ = 0;

void sumEven(ull startEven_, ull endEven_){
    for(int i=startEven_; i<=endEven_; i++){
        if((i%2) == 0){
            sumEven_+=i;
        }
    }
    std::cout << sumEven_ << std::endl;
}

void sumOdd(ull startOdd_, ull endodd_){
    for(int i=startOdd_; i<=endodd_; i++){
        if((i%2) == 1){
            sumOdd_+=i;
        }
    }
    std::cout << sumOdd_ << std::endl;
}

int main(){
    
    ull start = 0, end = 1900000000;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    // sumEven(start, end);
    // sumOdd(start, end);
    
    std::thread T1(sumEven, start, end);
    std::thread T2(sumOdd, start, end);
    
    T1.join();
    T2.join();
    
    auto end_time = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    
    std::cout << "sec: " << duration.count()/1e+6 << std::endl;
    
    return 0;
}