#include <iostream>
#include <vector>
#include <string>

void print(std::initializer_list<int> vals) {
    for(auto p = vals.begin(); p != vals.end(); ++p) {
        std::cout << *p << " ";
    }
    std::cout << "\n" ;
}

int main() {
    int a[] {1, 2, 3};
    std::vector<int> vec {4, 5, 6};
    std::vector<std::string> cities {"Frankfurt", "Berlin", "Bangalore"};
    print({12, 2, 5, 7, 11, 13, 17});
}