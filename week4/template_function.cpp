#include <string>

template <typename T>
auto sum(T a, T b) -> T {
	return a+b;
}

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename Container>
auto begin(Container& c) {
	return c.begin();
}

template <typename Container>
auto begin(const Container& c) {
	return c.begin();
}

int main() {
	int a = sum<int>(3, 5);
	double b = sum<double>(5.0, 3.0);
	std::string c = sum<std::string>("abc", "def");
	return 0;
}
