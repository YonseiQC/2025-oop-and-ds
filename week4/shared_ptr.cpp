#include <memory>
#include <iostream>

int main() {
	auto ptr1 = std::make_shared<std::string>("abc");

	std::cout << "Reference count of ptr1:" << ptr1.use_count() << '\n';
	auto ptr2 = ptr1;
	std::cout << "Reference count of ptr1:" << ptr1.use_count() << '\n';

	ptr2 = std::make_shared<std::string>("def");
	std::cout << "Reference count of ptr1:" << ptr1.use_count() << '\n';
	std::cout << "Reference count of ptr2:" << ptr2.use_count() << '\n';
	return 0;
}
