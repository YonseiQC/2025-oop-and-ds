#include <numeric>
#include <iostream>
#include <memory>

template <typename T>
class DynamicArray {
private:
	std::unique_ptr<T[]> ptr_;
	int length_;
	int capacity_;

	void double_size() {
		auto new_ptr = std::unique_ptr<T[]>(new T[2*length_]);
		std::copy(ptr_.get(), ptr_.get() + length_, new_ptr.get());
		ptr_ = std::move(new_ptr);
		capacity_ *= 2;
	}

public:
	DynamicArray(int capacity = 16) : length_(0), capacity_(capacity) {
		ptr_ = std::unique_ptr<T[]>(new T[capacity]);
	}

	DynamicArray(const DynamicArray& other) {
		length_ = other.length_;
		capacity_ = other.capacity_;
		ptr_ = std::unique_ptr<T[]>(new T[capacity_]);
		std::copy(other.ptr_.get(), other.ptr_.get() + length_, ptr_.get());
		// Don't forget to initialize all member variables!!
	}

	DynamicArray& operator=(const DynamicArray& other) {
		length_ = other.length_;
		capacity_ = other.capacity_;
		ptr_ = std::unique_ptr<T[]>(new T[capacity_]);
		std::copy(other.ptr_.geT(), other.ptr_.get() + length_, ptr_.get());
		// Don't forget to assign all member variables!!
		return *this;
	}

	int get_capacity() const {
		return capacity_;
	}

	int get_length() const {
		return length_;
	}

	T get_elt(int idx) const {
		return ptr_[idx];
	}

	void add_elt(T val) {
		if (length_ == capacity_) {
			double_size();
		}
		ptr_[length_++] = val;
	}

	T* begin() {
		return ptr_.get();
	}

	const T* begin() const {
		return ptr_.get();
	}

	T* end() {
		return ptr_.get() + length_;
	}

	const T* end() const {
		return ptr_.get() + length_;
	}
};
/* Encapsulation */

int main() {
	DynamicArray<int> arr(10); // make dynamic array with capacity = 10
	
	for(int i = 0; i < 10; i++) {
		arr.add_elt(i);
	}

	const DynamicArray<int> arr2 = arr;
	
	int sum = std::accumulate(arr2.begin(), arr2.end(), 0);
	std::cout << "sum: " << sum << '\n';

	DynamicArray<double> c;
	DynamicArray<std::string> d;
	DynamicArray<DynamicArray<int>> f;

	return 0;
}
