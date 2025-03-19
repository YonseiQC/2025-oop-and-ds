#include <algorithm>
#include <iostream>
#include <vector>

bool bigger_than_three(int elt) {
	return elt > 3;
}
bool bigger_than_five(int elt) {
	return elt > 5;
}

struct bigger_than {
	int comp_to;

	bigger_than(int v): comp_to{v} {}

	bool operator()(int val) {
		return val > comp_to;
	}
};

int main() {
	std::vector<int> vec{1,2,3,4,5};
	std::vector<int> vec2;

	std::copy_if(std::begin(vec), std::end(vec), std::back_inserter(vec2), bigger_than(3));

	for(int elt: vec2) {
		std::cout << elt << '\t';
	}
	std::cout << '\n';
	return 0;
}
