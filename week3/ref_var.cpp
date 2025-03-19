#include <iostream>
#include <format>

int main() {
	int a = 5;
	int& c = a;
	c = 3;

	std::cout << std::format("a is {}\n", a); // print 3
	return 0;
}
