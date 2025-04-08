#include <algorithm>
#include <iostream>
#include <vector>

void insertion_sort(int* arr, int length) {
	for(int i = 1; i < length; i++) {
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			std::swap(arr[j-1], arr[j]);
			--j;
		}
	}
}

int main() {
	std::vector<int> arr{1, -3, 4, -8, 4};
	insertion_sort(arr.data(), arr.size());

	for(int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';
	return 0;
}
