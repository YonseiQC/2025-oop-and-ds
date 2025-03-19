#include <iostream>
#include <format>
#include <utility>

int main() {
	int a = 5;
	int b = 3;
	std::swap(a, b);
	std::cout << std::format("a = {}, b = {}\n", a, b);
	return 0;
}
