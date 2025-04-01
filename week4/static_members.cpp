#include <iostream>

class Test {
private:
	static inline int instance_count = 0;

public:
	Test() {
		instance_count += 1;
	}

	int get_instance_count() const {
		return instance_count;
	}

	static void static_member_function() {
		std::cout << "Calling static_member_function\n";
		// We cannot use *this pointer* within a static member function
	}
};
// old style
// int Test::instance_count = 0; // initialization

int main() {
	for(int i = 0; i < 100; i++) {
		Test t;
	}

	Test t;
	std::cout << t.get_instance_count() << '\n';

	// We can call static member function with or without an instance
	Test::static_member_function();
	t.static_member_function();

	return 0;
}
