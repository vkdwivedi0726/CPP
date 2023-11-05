#include <algorithm>
#include <deque>
#include <iostream>

int main() {
    std::deque<int> coll = {1, 3, 19, 5, 13, 7, 11, 2, 17};

    int x = 5, y = 12;
    auto pos = find_if(coll.begin(), coll.end(), [=](int i) {return i > x && i < y;});
    std::cout << "first elem > 5 and < 12: " << *pos << std::endl;
}