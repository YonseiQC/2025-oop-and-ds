#include <string>
#include <iostream>

template <typename T>
class MyUniquePtr {
private:
	T* ptr_;
public:
	MyUniquePtr(T* ptr) {
		ptr_ = ptr;
	}

	MyUniquePtr(const MyUniquePtr& ) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;

	// called when we use *my_unique_ptr
	T& operator*() const {
		return *ptr_;
	}

	T* operator->() const {
		return ptr_;
	}

	~MyUniquePtr() {
		delete ptr_;
	}
};

int function() {
	int* ptr = MyUniquePtr(new int);
	if (blah blabh ) {
		return 1;
	}
	if (blah bbb) {

		return 1;
	}
	return 0;
}

int main() {
	MyUniquePtr int_unique_ptr(new int);
	MyUniquePtr string_unique_ptr(new std::string("ABCDE"));

	*int_unique_ptr = 10;

	std::cout << *int_unique_ptr << '\n';
	std::cout << string_unique_ptr->length() << '\n';
	return 0;
}
