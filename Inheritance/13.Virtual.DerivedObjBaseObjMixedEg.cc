#include <iostream>

using namespace std;

class Base {
    public:
    virtual void show() {cout << "IN base\n";}
};

class Derived : public Base {
    public:
    void show() {cout << "In derived\n";}
};

int main() {
    Base *bp, b;
    Derived d;
    bp = &d;
    bp->show();
    bp = &b;
    bp->show();

    return 0;
}