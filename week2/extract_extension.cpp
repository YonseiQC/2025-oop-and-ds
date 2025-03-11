#include <iostream>
#include <string>

int main() {
	std::string filename;
	std::cin >> filename;

	// extract extension
	const auto pos = filename.find_last_of('.');
	const std::string ext = filename.substr(pos + 1);
	std::cout << ext << '\n';

	return 0;
}
