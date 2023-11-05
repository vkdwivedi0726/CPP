#include <iostream>

using namespace std;

class Base {
    public:
    int fun() {cout << "Base::fun() called\n";}
    int fun(int i) {cout << "Base::fun(int i) cald\n";}
};

class Derived : public Base {
    public:
    int fun() {cout << "Derived::fun()\n";}
};

/*
    If Derived class writes its own method, then all functions of base
    class with same name becomes hidden, even if signature of base class
    functions are different.
*/

int main() {
    Derived d;
    d.fun(5);

    return 0;
}