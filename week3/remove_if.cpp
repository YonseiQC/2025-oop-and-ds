#include <algorithm>
#include <iostream>
#include <format>
#include <vector>

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

bool less_than_ten(int val) {
	return val < 10;
}

int main() {
	std::vector<int> vec{1, 10, 23, 4, 8, 9, 2, 7, 45, 1, 88, 0};

	auto it = std::remove_if(std::begin(vec), std::end(vec), less_than_ten);
	std::cout << format_vector(vec) << '\n';
	vec.erase(it, std::end(vec));

	std::cout << format_vector(vec) << '\n';

	return 0;
}
