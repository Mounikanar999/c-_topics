#include <iostream>
#include <memory>

class rectangle{
    private:
        unsigned int length;
        unsigned int breadth;
        static int count;  // static variable for maintaining count of rectangle objects created
    public:
        rectangle();
        rectangle(unsigned int, unsigned int);  // will consider as default and parameterized constructor due to method "overloading"
        // rectangle(unsigned int, unsigned int);
        rectangle(rectangle&);
        // rectangle(rectangle&&);
        
        // if we add inline keyword, then the definition of particular method will also store with main function in code section
        // so that the execution time is faster and eficient
        inline unsigned int get_length();
        inline unsigned int get_breadth();
        
        inline void set_length(unsigned int);
        inline void set_breadth(unsigned int);
        
        inline unsigned int area_rectangle();
        inline unsigned int perimeter_rectangle();
        
        inline bool is_square();
        
        inline virtual void display();  // by mentioning virtual for overrided method, we can achieve run time polymorphism in single or hirarchical inherited classes
        
        inline static int get_count();  // static member functions only accesses static data and not normal data in the class where it is declared
        
        ~rectangle();
};
int rectangle::count = 0;

class cuboid : public rectangle{
    private:
        unsigned int height;
    public:
        inline cuboid();
        inline cuboid(unsigned int);
        cuboid(cuboid& cub):rectangle(cub.get_length(), cub.get_breadth()){std::cout << "cuboid object constructed with previos cuboid" << std::endl; this->height = cub.height;}
        
        inline unsigned int get_height();
        inline void set_height(unsigned int);
        
        inline unsigned int area_cuboid();
        inline unsigned int perimeter_cuboid();
        
        inline bool is_perfect_cuboid();
        
        inline void display();
        
        inline ~cuboid();
};

rectangle::rectangle(){
    std::cout << "rectangle object constructed with no parameters" << std::endl;
    count++;
}

rectangle::rectangle(unsigned int length, unsigned int breadth){
    std::cout << "rectangle object constructed with parameters" << std::endl;
    count++;
    if(length < 1){
        this->length = 1;
    }else{
        this->length = length;
    }
    if(breadth < 1){
        this->breadth = 1;
    }else{
        this->breadth = breadth;
    }
}

rectangle::rectangle(rectangle& rect){
    std::cout << "rectangle object constructed with previous rectangle" << std::endl;
    count++;
    length = rect.get_length();
    breadth = rect.get_breadth();
}

unsigned int rectangle::get_length(){
    return length;
}

unsigned int rectangle::get_breadth(){
    return breadth;
}

void rectangle::set_length(unsigned int length){
    this->length = length;
}

void rectangle::set_breadth(unsigned int breadth){
    this->breadth = breadth;
}

unsigned int rectangle::area_rectangle(){
    return length*breadth;
}

unsigned int rectangle::perimeter_rectangle(){
    return 2*(length+breadth);
}

bool rectangle::is_square(){
    if(length == breadth){
        // std::cout << "perfect square" << std::endl;
        return true;
    }else{
        // std::cout << "not a perfect square" << std::endl;
        return false;
    }
}

void rectangle::display(){
    std::cout << "length of rectangle: " << get_length() << std::endl;
    std::cout << "breadth of rectangle: " << get_breadth() << std::endl;
    std::cout << "area of rectangle: " << area_rectangle() << std::endl;
    std::cout << "perimeter of rectangle is: " << perimeter_rectangle() << std::endl;
    std::cout << "created rectangle is square or not: " << is_square() << std::endl;
    // std::cout << "created rectangle objects: " << count << std::endl;
    std::cout << "created rectangle objects: " << get_count() << std::endl;
}

// static member functions only accesses static data and not normal data in the class where it is declared
int rectangle::get_count(){
    return count;
}

rectangle::~rectangle(){
    std::cout << "rectangle destructed" << std::endl;
}

cuboid::cuboid(){
    std::cout << "cuboid object constructed with no parameters" << std::endl;
}

cuboid::cuboid(unsigned int height){
    std::cout << "cuboid object constructed with paramaters" << std::endl;
    if(height < 1){
        this->height = 1;
    }else{
        this->height = height;
    }
}

// cuboid::cuboid(cuboid& cub):rectangle(cub.get_length(), cub.get_breadth()){
//     this->height = cub.height;
// }

unsigned int cuboid::get_height(){
    return height;
}

void cuboid::set_height(unsigned int height){
    this->height = height;
}

unsigned int cuboid::area_cuboid(){
    return (2*(get_length()*get_breadth())+(get_breadth()*get_height())+(get_height()*get_length()));
}

unsigned int cuboid::perimeter_cuboid(){
    return (4*(get_length()+get_breadth()+get_height()));
}

void cuboid::display(){
    std::cout << "length of cuboid is: " << get_length() << std::endl;
    std::cout << "breadth of cuboid is: " << get_breadth() << std::endl;
    std::cout << "height of created cuboid is: " << get_height() << std::endl;
    std::cout << "area of cuboid is: " << area_cuboid() << std::endl;
    std::cout << "perimeter of cuboid is: " << perimeter_cuboid() << std::endl;
}

cuboid::~cuboid(){
    std::cout << "cuboid destructed" << std::endl;
}

int main(){
    
    // rectangle* ptr = new rectangle;
    // ptr->set_length(10);
    // ptr->set_breadth(10);
    
    // std::cout << ptr->get_length() << std::endl;
    // std::cout << ptr->get_breadth() << std::endl;
    // ptr->display();
    
    // rectangle* ptr2 = new rectangle(*ptr);
    
    // std::cout << ptr2->get_length() << std::endl;
    // std::cout << ptr2->get_breadth() << std::endl;
    // ptr2->display();
    
    // std::cout << "static count value can access via class name too: " << rectangle::get_count() << std::endl;
    
    // std::cout << "if 0:not square, if 1:perfect square = " << ptr2->is_square() << std::endl;
    
    // cuboid* ptr3 = new cuboid(10);
    // cuboid* ptr4 = new cuboid(*ptr3);
    // std::cout << ptr4->get_length() << std::endl;
    // std::cout << ptr4->get_breadth() << std::endl;
    // std::cout << ptr4->get_height() << std::endl;
    
    // rectangle* ptr5 = new cuboid(10);
    // rectangle* ptr5 = new cuboid(10);
    
    // std::cout << ptr5->get_length() << std::endl;
    // std::cout << ptr5->get_breadth() << std::endl;
    // std::cout << ptr5->get_height() << std::endl;
    
    // ptr5->display();

    // delete ptr2;
    // delete ptr;
    // delete ptr3;
    // delete ptr4;
    // delete ptr5;

    // std::unique_ptr<rectangle> un_pt(rectangle());
    std::unique_ptr<rectangle> un_pt = std::make_unique<rectangle> (5, 8);
    un_pt->display();

    // std::unique_ptr<rectangle> un_pt(un_pt);    // uniqueptr cannot be assigned to another uniquepointer
    // un_pt->display();

    // std::shared_ptr<rectangle> un_pt = std::make_unique<rectangle> (5, 8);
    // un_pt->display();

    // // std::shared_ptr<rectangle> un_pt2 = std::make_unique<rectangle> (un_pt);
    // std::shared_ptr<rectangle> un_pt2(un_pt);
    // un_pt2->display();
    
    return 0;
}