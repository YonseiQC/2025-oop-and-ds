#include <iostream>
#include <vector>

// Find an element from a given sorted array
// If there is such an element, return the index
// Otherwise, return -1
int binary_search(int* arr, int begin, int end, int elt) {
	if (end - begin <= 1) {
		if(arr[begin] == elt) {
			return begin;
		} else {
			return -1;
		}
	}

	int mid = (begin+end)/2;
	if (arr[mid] > elt) {
		return binary_search(arr, begin, mid, elt);
	} else {
		return binary_search(arr, mid, end, elt);
	}
}

int main() {
	std::vector<int> arr{1, 2, 8, 9, 100, 123, 1000};
	std::cout << binary_search(arr.data(), 0, arr.size(), 20) << '\n'; // Prints -1 since 20 is not in the vector
	std::cout << binary_search(arr.data(), 0, arr.size(), 123) << '\n'; // Prints 5 since arr[5]==123
	return 0;
}
