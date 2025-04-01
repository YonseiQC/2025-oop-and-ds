#include <cassert>
#include <iostream>
#include <memory>
#include <vector>


int main() {
	auto ptr = std::make_unique<std::vector<int>>(100, 3);

	assert(ptr->size() == 100);

	// auto ptr2 = ptr; // This line does not work!
	auto ptr3 = std::move(ptr); // this line work!
	
	assert(ptr.get() == nullptr); // 
	
	std::cout << "Size of *ptr3: " << ptr3->size() << '\n';
	return 0;
}
