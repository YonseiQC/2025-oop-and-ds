#include <iostream>
int main() {
	int x = 0;
	auto func = [&x]() {
		x += 1;
	};
	func();
	std::cout << x << '\n';
	func();
	std::cout << x << '\n';
	return 0;
}
