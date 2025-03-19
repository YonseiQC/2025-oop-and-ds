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

	bigger_than func(5);
	std::cout << func(3) << '\t' << func(10) << '\n'; // prints 0   1
	
	auto it = find_if(std::begin(vec), std::end(vec), bigger_than(3));

	if(it == std::end(vec)) {
		// Could not find an element
		std::cout << "There is no such element\n";
	} else {
		std::cout << "There is such an element\n";
	}
	return 0;
}
