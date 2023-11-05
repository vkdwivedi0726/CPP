#include <iostream>

using namespace std;

class Base {
    protected:
    int a;
    public:
    Base() {a = 0;}
};

class Derived1 : public Base {
    public:
    int c;
};

class Derived2 : public Base {
    public:
    int c;
};

class DerivedDerived: public Derived1, Derived2 {
    public:
    void show() {cout << a; }
};

/*
Diamond problem -- Here since Base is extended in both D1 and D2, 
In DD, we are not sure where "a" is coming from, hence it does not compile.
To solve this problem:

#include using namespace std; 
class Base { 
    protected: int a; 
    public: 
    Base() {a = 0;} 
}; 

class Derived1: virtual public Base { 
    public: int c; 
}; 

class Derived2: virtual public Base { 
    public: int c; 
}; 

class DerivedDerived: public Derived1, public Derived2 { 
    public: void show() { cout << a; } 
}; 

int main(void) { 
    DerivedDerived d; 
    d.show(); 
    return 0; 
}
*/

int main() {
    DerivedDerived d;
    d.show();
    return 0;
}