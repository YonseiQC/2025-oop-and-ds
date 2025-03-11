#include <iostream>
int main() {
	int arr[4] = {1, 2, 3, 4};
	const int* pt = &arr[1];
	*pt = 5; // Compile Error!
	for(int i = 0; i < 4; i++) {
		std::cout << arr[i];
		if (i != 3) {
			std::cout << ", ";
		}
	}
	std::cout << '\n';
	// prints 1, 5, 3, 4
	return 0;
}
