#include <iostream>

using namespace std;


class Base {
    public:
    void show() {
        cout << "In base\n";
    }
};

class Derived: public Base {
    public:
    int x;
    void show() {
        cout << "In derived\n";
    }
    Derived() {x = 10;}
};
/*
    A base class pointer can point to derived class object, 
        but we can only access base class members or virtual functions using base 
        class pointer.
        In below example, bp->show() prints "In base" and cout << bp->x; does not 
            allow code to compile.
*/

int main() {
    Base *bp, b;
    Derived d;
    bp = &d;
    bp->show();
    cout << bp->x;
    return 0;
}