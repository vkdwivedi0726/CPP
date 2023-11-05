#include <iostream>

int main() {
    [] () -> double {return 42;};
    int x {};
    int y {42};
    auto q = [x, &y] {std::cout << x << " " << y << std::endl;
        ++y;
    };

    x = y = 77;
    q();
    q();
    std::cout << "final y: " << y << std::endl;
}