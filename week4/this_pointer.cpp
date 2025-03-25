#include <string>

class Test;
void a_function_using_test(const Test& t);

class Test {
private:
	std::string name_;

public:
	Test(const std::string& name) {
		name_ = name; // this is the same as the following line
		this->name_ = name;
	}

	void do_something() {
		a_function_using_test(*this);
	}
};

void a_function_using_test(const Test& t) {
	// do something
}

