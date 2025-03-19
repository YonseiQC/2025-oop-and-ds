#include <algorithm>
#include <iostream>
#include <vector>
#include <format>
#include <random>

std::string format_vector(const std::vector<int>& vec) {
	std::string res = "[";
	if (vec.size() == 0) {
		res += "]";
		return res;
	}

	for(int i = 0; i < vec.size()-1; i++) {
		res += std::format("{},", vec[i]);
	}
	res += std::format("{}]", vec.back());
	return res;
}

void add_elt(std::vector<int>& vec, int elt) {
	auto it = std::lower_bound(std::begin(vec), std::end(vec), elt);
	vec.insert(it, elt);
}

bool find_elt(std::vector<int>& vec, int elt) {
	return std::binary_search(std::begin(vec), std::end(vec), elt);
}

int main() {
	std::vector<int> vec;

	// The following is the basic scheme to generate pseudorandom numbers
	std::mt19937 re{1557};
	std::cout << re() << '\n'; // generate a 32-bit integer
	std::uniform_int_distribution<int> dist(0, 100);

	for(int i = 0; i < 30; i++) {
		add_elt(vec, dist(re));
	}

	std::cout << format_vector(vec) << '\n';

	return 0;
}
