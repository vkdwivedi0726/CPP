#include <iostream>

using namespace std;

class Base {};
class Derived: public Base {};
/*
    A base pointer/reference can point/refer to a derived class object but
        other way round is not possible.
*/
int main() {
    Base *bp = new Derived();
    Derived *dp = new Base();
}