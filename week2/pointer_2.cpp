#include <iostream>

int sum_array(const int* arr, int length) {
	int res = 0;
	for(int i = 0; i < length; i++) {
		res += arr[i];
	}
	return res;
}

int main() {
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	sum_array(arr, 8);
	return 0;
}
