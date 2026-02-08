#include <iostream>

class example_Deepcopy{
    private:
        int value;  // array size 
        int* p;  // array of "pointer variable"
    public:
        example_Deepcopy(int value){this->value = value; p = new int[value];}
        // example_Deepcopy(example_Deepcopy& example_Deepcopy_copy){this->value = example_Deepcopy_copy.value; p = example_Deepcopy_copy.p;}   // shallow copy definition
        example_Deepcopy(example_Deepcopy& example_Deepcopy_copy){this->value = example_Deepcopy_copy.value; p = new int[value];}               // deep copy definition
        ~example_Deepcopy(){std::cout << "object destructed" << std::endl; delete p;}
};

int main(){
    
    example_Deepcopy ED(5);
    example_Deepcopy ED1(ED);
    // ED1.*p[1] = 5;
    // ED1.p[1] = 5;  // this logic works for assigning data if we implement setter method for filling array values
    
    return 0;
}

// to fill data in array
/*

#include <iostream>
#include <cstring>  // for std::copy

class example_Deepcopy {
private:
    int value;
    int* p;

public:
    // Constructor
    example_Deepcopy(int val) : value(val), p(new int[val]) {
        std::fill(p, p + value, 0);  // Initialize to 0
    }
    
    // ✅ PROPER Deep Copy Constructor
    example_Deepcopy(const example_Deepcopy& other) : value(other.value), p(new int[other.value]) {
        std::copy(other.p, other.p + other.value, p);  // Copy data!
    }
    
    // ✅ Setter for array access
    void setValue(int index, int val) {
        if (index >= 0 && index < value) {
            p[index] = val;
        }
    }
    
    // ✅ Print array
    void print() {
        for (int i = 0; i < value; i++) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }
    
    ~example_Deepcopy() {
        std::cout << "Destructor called" << std::endl;
        delete[] p;
    }
};

int main() {
    example_Deepcopy ED(5);
    example_Deepcopy ED1(ED);  // Deep copy
    
    ED.setValue(1, 10);    // ED array[1] = 10
    ED1.setValue(1, 5);    // ED1 array[1] = 5 (independent!)
    
    std::cout << "ED:  ";
    ED.print();   // Independent copy
    std::cout << "ED1: ";
    ED1.print();
    
    return 0;
}

*/