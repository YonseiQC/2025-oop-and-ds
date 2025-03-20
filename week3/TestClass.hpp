#include <iostream>
#include <string>
#include <format>

class TestClass {
private:
	std::string name_;
public:
	TestClass() {
		static int counter = 0;
		name_ = std::format("NoName_{}", counter);
		std::cout << std::format("An instance name={} is constructed.\n", name_);
	}

	TestClass(const std::string& name) {
		name_ = name;
		std::cout << std::format("An instance name={} is constructed.\n", name_);
	}

	TestClass(const TestClass& other) {
		name_ = other.name_ + "CopyConstructed";
		std::cout << std::format("An instance name={} is copy constructed from {}.\n", name_, other.name_);
	}

	TestClass& operator=(const TestClass& other) {
		std::cout << std::format("An instance name={} is copy assigned from {}. The new name will be name={}\n", name_, other.name_, other.name_ + "CopyAssigned");
		name_ = other.name_ + "CopyAssigned";
		return *this;
	}

	~TestClass() {
		std::cout << std::format("The instance with name={} is destroyed.\n", name_);
	}
};
