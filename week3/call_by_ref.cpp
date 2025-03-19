#include <iostream>
#include <string>

// Since we use const reference, we do not copy the argument
std::string first_half_of_str(const std::string& arg) {
	return arg.substr(0, arg.size() / 2);
}

int main() {
	std::string str("This is reallllyyyy loooooooooooooooooooooooooooongggggggggggggg string");
	std::cout << first_half_of_str(str) << '\n';
	return 0;
}
