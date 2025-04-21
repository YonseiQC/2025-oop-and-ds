#include <functional>
#include <iostream>

class BiggerThan {
private:
	int val_;

public:
	BiggerThan(int val) : val_(val) {
	}

	bool operator()(int elt) const {
		return elt > val_;
	}
};

bool bigger(int a, int b) {
	return a > b;
}

/*
template<typename Func, typename... Args>
auto run_func(Func func, Args... args)-> typename std::invoke_result<Func, Args...>::type {
	return func(std::forward<Args>(args)...);
}
*/

template<typename Func>
bool apply_func1(Func func, int arg1, int arg2) {
	return func(arg1, arg2);
}

bool apply_func2(std::function<bool(int, int)> func, int arg1, int arg2) {
	return func(arg1, arg2);
}

bool apply_func3(bool (*func)(int, int), int arg1, int arg2) {
	return func(arg1, arg2);
}

int main() {
	auto bigger_than = BiggerThan(5);

	std::cout << "8 bigger than 5? " << bigger_than(8) << '\n';
	std::cout << "3 bigger than 5? " << bigger_than(3) << '\n';

	std::function<bool(int, int)> func1 = bigger;
	auto func2 = [](int a, int b) {
		return a > b;
	};

	std::function<bool(int, int)> func3 = func2;

	std::cout << func1(1, 3) << '\n';
	std::cout << apply_func1(func1, 1, 3) << '\n'; // Same
												  // You can pass a lambda using a template
	std::cout << apply_func2(func1, 1, 3) << '\n'; // Or using std::function
	//std::cout << apply_func3(func1, 1, 3) << '\n'; // But not using a function pointer
	
	return 0;
}
