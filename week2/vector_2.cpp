#include <vector>
#include <iostream>

int main() {
	std::vector<int> v;
	const int size = 1'000'000;
	v.reserve(size);

	std::cout << v.capacity() << '\n'; // print 1'000'000

	for(int i = 0; i < size; i++) {
		v.insert(std::end(v), i);
		//v.insert(std::begin(v), i);
	}

	return 0;
}
