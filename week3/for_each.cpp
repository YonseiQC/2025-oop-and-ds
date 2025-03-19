#include <algorithm>
#include <iostream>
#include <vector>

void print(int val) {
	std::cout << val << '\n';
}
int main() {
	std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
	std::for_each(std::begin(vec), std::end(vec), print);
	return 0;
}
