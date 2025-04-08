#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

void merge_sort(int* arr, int begin, int end) {
	if(end - begin <= 1) {
		return ;
	}
	const int k =(begin + end)/2;
	merge_sort(arr, begin, k);
	merge_sort(arr, k, end);

	std::vector<int> sorted;
	int i = begin;
	int j = k;
	while(i < k && j < end) {
		if(arr[i] < arr[j]) {
			sorted.push_back(arr[i]);
			++i;
		} else {
			sorted.push_back(arr[j]);
			++j;
		}
	}

	if(i != k) {
		std::copy(arr + i, arr + k, std::back_inserter(sorted));
	} else {
		std::copy(arr + j, arr + end, std::back_inserter(sorted));
	}
	std::copy(std::begin(sorted), std::end(sorted), arr + begin);
}
int main() {
	std::vector<int> arr{1, 0, 4, 3, 9, 8, 100, 30, 29, 1000, 300};
	merge_sort(arr.data(), 0, arr.size());
	for(const auto elt: arr) {
		std::cout << elt << ", ";
	}
	std::cout << '\n';
	return 0;
}
