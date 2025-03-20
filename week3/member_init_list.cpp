#include "TestClass.hpp"

class A {
private:
	TestClass instance_;

public:
	A() { // default constructor without initialization list
		instance_ = TestClass("A");
	}
	// versus
	A(int): instance_("B") { // This line directly calls a constructor
		// with initialization list
	}
};
int main() {
	{
		// The following line calls two constructor and two destructor of TestClass
		A a;
	}
	{
		// The following line calls one constructor and one destructor of TestClass
		A b(1);
	}
	return 0;
}
