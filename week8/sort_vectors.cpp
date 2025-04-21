#include <vector>
#include <algorithm>
#include <string>
#include <format>
#include <iostream>

bool less_than(const std::vector<int>& lhs, const std::vector<int>& rhs) {
	if(lhs.size() < rhs.size()) {
		return true;
	}
	if(lhs.size() > rhs.size()) {
		return false;
	}

	for(int i = 0; i < lhs.size(); i++) {
		if(lhs[i] < rhs[i]) {
			return true;
		} else if(lhs[i] > rhs[i]) {
			return false;
		}
	}
	return false; // all elements are equal
}

// Do not take too much attention to this function now
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

int main() {
	std::vector<std::vector<int>> arr{
		std::vector<int>{1, 2, 3, 4, 5, 6},
		std::vector<int>{1, 2, 5},
		std::vector<int>{4, 5, 6},
		std::vector<int>{9, 10}
	};
	std::sort(arr.begin(), arr.end(), less_than);
	for(const auto& vec: arr) {
		std::cout << format_vector(vec) << '\n';
	}
	return 0;
}
