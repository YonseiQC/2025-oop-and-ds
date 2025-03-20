#include "TestClass.hpp"
int main() {
	TestClass* inst = new TestClass("inst");
	delete inst;

	// The same can be used for int[]
	int* ptr = new int[500];
	delete[] ptr;
	
	return 0;
}
