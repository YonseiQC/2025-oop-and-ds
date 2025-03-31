#include <array>

template <typename T, int N>
class MyArray {
private:
	T arr[N];
public:

};

template<int N>
int sum_arr(const std::array<int, N>& arr) {

}

int main() {
	int arr1[5]; // C-style array
	std::array<int, 5> arr2; // C++ array
	return 0;
}
