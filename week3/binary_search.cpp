#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec{0, 1, 2, 3, 4, 4, 5, 6, 7, 8};
	auto it1 = std::lower_bound(std::begin(vec), std::end(vec), 4);
	auto it2 = std::upper_bound(std::begin(vec), std::end(vec), 4);
	std::cout << std::distance(std::begin(vec), it1) << '\n';
	std::cout << std::distance(std::begin(vec), it2) << '\n';
	return 0;
}
