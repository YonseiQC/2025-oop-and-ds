#include <iostream>
#include <string>

int main() {
	std::string str;
	std::getline(std::cin, str); // str is called by reference
	std::string rev_str(std::rbegin(str), std::rend(str));
	std::cout << rev_str << '\n';
	return 0;
}
