#include <iostream>

using namespace std;

class Base1 {
    public:
    char c;
};

class Base2 {
    public:
    int c;
};
/*
This is similar to Diamond problem. 
    Since c is present in Base1 and Base2 -- not sure which c to consider.
Solution : using resolution operator

#include using namespace std; 
class Base1 { 
    public: char c; 
}; 

class Base2 { 
    public: int c; 
}; 

class Derived: public Base1, public Base2 { 
    public: void show() { cout << Base2::c; } 
}; 

int main(void) { 
    Derived d; 
    d.show(); 
    return 0; 
}

*/
class Derived : public Base1, public Base2 {
    public:
    void show() {cout << c;}
};

int main() {
    Derived d;
    d.show();
    return 0;
}