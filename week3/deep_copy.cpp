#include <iostream>
#include <vector>
#include <format>

int main() {
	std::vector<int> a{1, 2, 3, 4, 5};
	std::vector<int> b = a; // deep copy!
	b[3] = 8;
	std::cout << std::format("a[3] is {}\n", a[3]);
	std::cout << std::format("b[3] is {}\n", b[3]);
	return 0;
}
