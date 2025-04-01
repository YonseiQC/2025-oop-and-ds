#include <iostream>

class Test {
public:

	void print() {
		std::cout << "Print member function for non-const instance\n";
	}

	void print() const {
		std::cout << "Print member function for const instance\n";
	}
};

int main() {
	Test a;
	a.print();

	const Test b;
	b.print();

	return 0;
}
