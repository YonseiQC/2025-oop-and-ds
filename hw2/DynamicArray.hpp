#include <numeric>
#include <iostream>

class DynamicArray {
private:
	int* ptr_;
	int length_;
	int capacity_;

	void double_size() {
		int* new_ptr = new int[2 * capacity_];
		for(int i = 0; i < length_; i++) {
			new_ptr[i] = ptr_[i];
		}
		ptr_ = new_ptr;
		capacity_ *= 2;
	}

public:
	explicit DynamicArray(int capacity = 16) : length_(0), capacity_(capacity) {
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
		if(this == &other) {
			return *this;
		}
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

	int& operator[](int idx) {
		return ptr_[idx];
	}

	const int& operator[](int idx) const {
		return ptr_[idx];
	}

	void push_back(int val) {
		if (length_ == capacity_) {
			double_size();
		}
		ptr_[length_++] = val;
	}

	int back() const {
		return ptr_[length_-1];
	}

	void pop_back() {
		--length_;
	}

	~DynamicArray() {
		delete[] ptr_;
	}
};
