#include <iostream>
using namespace std;

class Base {
    public:
    int x, y;
    public:
    Base(int i, int j) {x = i; y = j;}
};

/*
This example is to show that we cannot directly use variables from base class 
    inside the Derived class. If you want to initialize variables, then use 
    the Base constructor to set variables
    #include using namespace std; 
    class Base { 
            public : int x, y; 
            public: Base(int i, int j){ x = i; y = j; } 
    }; 
    
    class Derived : public Base { 
        public: Derived(int i, int j): Base(i, j) {} 
        void print() {cout << x <<" "<< y; } 
    }; 
    
    int main(void) { 
        Derived q(10, 10); 
        q.print(); 
        return 0; 
    } 
*/
class Derived : public Base {
    public:
    Derived(int i, int j): x(i), y(j) {}
    void print() {cout << x << " " << y << "\n";}
};

int main() {
    Derived q(10, 10);
    q.print();
    return 0;
}