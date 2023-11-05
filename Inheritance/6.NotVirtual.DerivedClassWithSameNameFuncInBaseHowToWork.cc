#include <iostream>
using namespace std;

class Base {
    public:
    void fun() {cout << "Base::fun() cald\n";}
    void fun(int i) {cout << "Base::fun(int i) cald\n";}
    void func(int i) {cout << "Base::func(int i) cald\n";}
};

class Derived : public Base {
    public:
    void fun() {cout << "Derived::fun() cald\n";}
};

/*
So, if the name of function in base is same, and you want to call it, then
    use resolution operator and then call base class func.
    Also, be noted that you can still call functions that are of diff name
    in base class. shown below in example (func(4))
*/

int main() {
    Derived d;
    d.fun();
    d.func(4);
    d.Base::fun(5);

    return 0;
}