#include <bitset>
#include <iostream>
#include <vector>

void print() {}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    std::cout << firstArg << std::endl;
    print(args...);
}

/*
template <typename T>
using Vec = std::vector<T, MyAlloc<T>>;

Vec<int> coll;
*/
int main() {
    print (7.5, "hello", std::bitset<16>(377), 42);
}