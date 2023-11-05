#include <iostream>
#include <set>

class X {
    public:
    X() {}
    X(const X& lvalue) {}
    X(X&& rvalue) {}
};


//Whenever we insert into a collection -- it creates are temporary copy of the object. 
/**
 * 
 *  namespace std {
 *      template <typename T, ...> class set {
 *          public:
 *              ... insert (const T& v); //copy value of v
 *  }
 * }
 * 
*/
void CreateAndInsert(std::set<X>& coll) {
    X x;
    coll.insert(x);
}

/**
 * X x;
 * coll.insert(x); // inserts copy of x (OK, x is still used)
 * ...
 * coll.insert(x+x); // moves (or copies) contents of temporary rvalue
 * ...
 * coll.insert(std::move(x)); // moves (or copies) contents of x into coll
 * 
 * Last 2 inserts need not do copy, instead we can use std::move() 
 * 
 * namespace std {
 *      template <typename T, ...> class set {
 *          public:
 *              ... insert (const T& x); //for lvalues: copies the value
 *              ... insert (T&& x);  //for rvalues: moves the value
 *  }
 * } 
*/


int main() {
    std::set<X> coll;
    CreateAndInsert(coll);
}


/*
Overloading Rules for Rvalue and Lvalue References
The overloading rules for rvalues and lvalues are as follows:3
• If you implement only
    void foo(X&);
    without void foo(X&&), the behavior is as in C++98: foo() can be called for lvalues but not
        for rvalues.
• If you implement
    void foo(const X&);
    without void foo(X&&), the behavior is as in C++98: foo() can be called for rvalues and for
        lvalues.
• If you implement
    void foo(X&);
    void foo(X&&);
    or
    void foo(const X&);
    void foo(X&&);
    you can distinguish between dealing with rvalues and lvalues. The version for rvalues is allowed
        to and should provide move semantics. Thus, it can steal the internal state and resources of the
        passed argument.
• If you implement
    void foo(X&&);
    but neither void foo(X&) nor void foo(const X&), foo() can be called on rvalues, but
        trying to call it on an lvalue will trigger a compile error. Thus, only move semantics are provided
        here.
*/