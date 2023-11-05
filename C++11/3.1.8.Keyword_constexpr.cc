#include <iostream>
#include <array>
#include <limits>

std::array<float, std::numeric_limits<short>::max()> a;

int main() {
    std::cout << a[0] << std::endl;
}