#include <iostream>

using namespace std;

class Base1 {
    public:
    Base1() {cout << "Base1 ctor called\n";}
};

class Base2 {
    public:
    Base2() {cout << "Base2 ctor called\n";}
};

class Derived : public Base1, public Base2 {
    public:
    Derived() {cout << "Ctor Derived!\n";}
};

int main() {
    Derived d;
    return 0;
}