#include <iostream> 
#include <vector>

//Default template parameters
template <typename T, typename container = std::vector<T>>
class MyClass;

//Keyword typename
template <typename T>
class MyClass1 {
    typename T::SubType * ptr;
};

class Q {
    typedef int SubType; //Subtype could have been another class as well
    // calss SubType;
};

MyClass1<Q> x;

int main() {}