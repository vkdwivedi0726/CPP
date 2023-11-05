#include <iostream>

using namespace std;

class P {public:
    void print() {cout << "Inside P\n";}
};

class Q : public P {
    public:
    void print() {cout << "Inside Q\n";}
};
/*
Here the trick is --> Since the func is not present in R. So it is looked up in 
    inheritance hierarchy. It is searched linearly up in the inheritance.
*/

class R: public Q {};

int main() {
    R r;
    r.print();

    return 0;
}