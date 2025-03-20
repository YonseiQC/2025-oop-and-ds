#include "TestClass.hpp"

TestClass A("Global");

void func() {
	TestClass A("WithInFunction");
}

int main() {
	TestClass A("WithInMain");
	{ // Scope 1
		TestClass A("WithInScope1");
	}
	func();
	{ // Scope 1
		TestClass A("WithInScope2");
	}
	return 0;
}
