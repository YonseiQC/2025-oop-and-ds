#include <cstdlib>
#include <iostream>

class DynamicArray {
private:
	int* ptr_;
	int length_;
	int capacity_;

	void double_size() {
		int* new_ptr = (int*)malloc(sizeof(int) * 2 * capacity_);
		for(int i = 0; i < length_; i++) {
			new_ptr[i] = ptr_[i];
		}
		ptr_ = new_ptr;
		capacity_ *= 2;
	}

public:
	DynamicArray(int capacity = 16) : length_(0), capacity_(capacity) {
		ptr_ = new int[capacity];
	}

	DynamicArray(const DynamicArray& other) {
		length_ = other.length_;
		capacity_ = other.capacity_;
		ptr_ = new int[capacity_];
		std::copy(other.ptr_, other.ptr_ + length_, ptr_);
		// Don't forget to initialize all member variables!!
	}

	DynamicArray& operator=(const DynamicArray& other) {
		delete[] ptr_;

		length_ = other.length_;
		capacity_ = other.capacity_;
		ptr_ = new int[capacity_];
		std::copy(other.ptr_, other.ptr_ + length_, ptr_);
		// Don't forget to assign all member variables!!
		return *this;
	}

	int get_capacity() const {
		return capacity_;
	}

	int get_length() const {
		return length_;
	}

	int get_elt(int idx) const {
		return ptr_[idx];
	}

	void push_back(int val) {
		if (length_ == capacity_) {
			double_size();
		}
		ptr_[length_++] = val;
	}

	void insert(int index, int val) {
		if (length_ == capacity_) {
			double_size();
		}
		for(int i = length; i > index; --i) {
			ptr_[i + 1] = ptr_[i];
		}
		ptr_[index] = val;
	}

	~DynamicArray() {
		delete[] ptr_;
	}
};
/* Encapsulation */

int main() {
	DynamicArray arr(10); // make dynamic array with capacity = 10
	
	const DynamicArray arr2 = arr; // calling a copy constructor
	
	std::cout << "arr2[0]: " << arr2.get_elt(0) << '\n';

	return 0;
}
