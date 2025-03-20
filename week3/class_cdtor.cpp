#include <iostream>

class TestClass {
public:
	TestClass() {
		std::cout << "Constructor without arguments\n";
	}
	TestClass(int val) {
		std::cout << "Constructor with single int argument\n";
	}
	TestClass(int val1, int val2) {
		std::cout << "Constructor with two int arguments\n";
	}

	~TestClass() {
		std::cout << "Destructor\n";
	}
};

int main() {
	TestClass A;
	TestClass B(); // This is function declaration!
				   // It is called the Most vexing parse (https://en.wikipedia.org/wiki/Most_vexing_parse)
	TestClass C(0);
	TestClass D(0, 0);
	return 0;
}
