#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
    virtual string print() const {
        return "Base print\n";
    }
};

class Derived : public Base {
    public:
    virtual string print() const {
        return "Derived print\n";
    }
};

void describe(Base p) {
    cout << p.print() << endl;
}

/*
Note that an object of Derived is passed in describe(d), (NOT POINTER)
    but print of Base is called. 
The describe function accepts a parameter of Base type. 
This is a typical example of object slicing, when we assign an 
    object of derived class to an object of base type, the derived class 
    object is sliced off and all the data members inherited from base class 
    are copied. Object slicing should be avoided as there may be surprising 
    results like above. As a side note, object slicing is not 
    possible in Java. In Java, every non-primitive variable is actually 
    a reference.
*/


int main() {

    Base b;
    Derived d;
    describe(b);
    describe(d);

    return 0;
}