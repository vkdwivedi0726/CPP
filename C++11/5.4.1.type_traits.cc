#include <iostream>

template <typename T>
void foo(const T &val) {
    if(std::is_pointer<T>::value) {
        std::cout << "called for pointer" << std::endl;
    } else {
        std::cout << "called for value" << std::endl;
    }
}

//foo impl for pointer types
template <typename T>
void foo_impl(const T &val, std::true_type) {
    std::cout << "called for pointer type" << std::endl;
}

int main() {

}