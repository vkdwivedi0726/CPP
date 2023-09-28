#include <iostream>
#include <vector>


int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
	for(const auto e : vec)
		std::cout << e << " ";
	std::cout << std::endl;
}
