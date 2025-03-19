#include <algorithm>
#include <iostream>
#include <string>

char my_toupper(char c) {
	return (char)std::toupper(c);
}
int main() {
	std::string str = "this string has all lowercase letters.";
	std::transform(std::begin(str), std::end(str), std::begin(str), my_toupper);

	// The above line is the same as the following for loop
	/*
	for(auto it = std::begin(str); it != std::end(str); ++it) {
		*it = my_toupper(*it);
	}
	*/

	std::cout << str << '\n';
	return 0;
}
