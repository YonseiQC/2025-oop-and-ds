#include <iostream>
#include <format>

class Test {
public:
	int* ptr;

	Test() {
		ptr = new int(5);
		// *ptr = 5;
	}

	~Test() {
		delete ptr;
	}

	Test(const Test& rhs) = default;
	Test& operator=(const Test& rhs) = default;
};

int main() {
	Test t;
	Test t2(t); // this only copy the pointer (shallow copy)

	std::cout << std::format("Value of t: {}\n", *t.ptr); // print 5
	*(t2.ptr) = 10;
	std::cout << std::format("Value of t: {}\n", *t.ptr); // print 10
	return 0;
}

